#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = true;
const int maxn = 1e4 + 10;
const int MOD = 1000000007;
vector<int> vx[maxn], vy[maxn];
int x[maxn], y[maxn], d[maxn];
bool vis[maxn];

struct Node {
    int id, v;
    Node(int id = 0, int v = 0) : id(id),v(v) {}
};
bool operator < (Node a, Node b) {
    return a.v >= b.v;
}
priority_queue<Node> Q;
int mabs(int a) {
    return a > 0 ? a : -a;
}
void itex(int xx, int yy, int id) {
    for (int idx : vx[xx]) if (!vis[idx]) {
        if (mabs(y[idx]-yy)==1) {
            d[idx] = min(d[idx],d[id]);
            Q.push(Node(idx,d[idx]));
        }
        else {
            d[idx] = min(d[idx],d[id]+1);
            Q.push(Node(idx,d[idx]));
        }
    }
}
void itey(int xx, int yy, int id) {
    for (int idy : vy[yy]) if (!vis[idy]) {
        if (mabs(x[idy]-xx)==1) {
            d[idy] = min(d[idy],d[id]);
            Q.push(Node(idy,d[idy]));
        }
        else {
            d[idy] = min(d[idy],d[id]+1);
            Q.push(Node(idy,d[idy]));
        }
    }
}
int main() {
    int n, m, k, st, ed = -1; scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < maxn; i++) d[i] = MOD;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i]==1&&y[i]==1) st=i;
        if (x[i]==n&&y[i]==m) ed = i;
        vx[x[i]].push_back(i);
        vy[y[i]].push_back(i);
    }

    Q.push(Node(st,0));

    while(!Q.empty()) {
        Node tp = Q.top(); Q.pop(); 
        if (vis[tp.id]) continue;
        vis[tp.id] = true;

        int xx = x[tp.id], yy = y[tp.id], v = tp.v;
        itex(xx, yy, tp.id);
        if (xx>0) itex(xx-1,yy,tp.id);
        itex(xx+1,yy,tp.id);

        itey(xx, yy, tp.id);
        if (yy>0) itey(xx,yy-1,tp.id);
        itey(xx,yy+1,tp.id);
    }
    for (int i = 0; i < n; i++) {
        if (debug) {
            printf("d[%d]: %d\n", i, d[i]);
        }
    }
    if (ed!=-1) {
        if (d[ed]==MOD) printf("-1\n");
        else printf("%d\n", d[ed]);
    }
    else {
        int ans = MOD;
        for (int idx:vx[n]) {
            ans = min(ans, d[idx]+1);
        }
        for (int idy:vy[m]) {
            ans = min(ans, d[idy]+1);
        }
        if (ans == MOD) printf("-1\n");
        else printf("%d\n", ans);
    }

	return 0;
}