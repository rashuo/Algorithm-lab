#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 2e5+10;
const int mod = 1e9+10;
const int inf = mod*2;
typedef long long ll;
int n, x;
struct Tri {
    int l, r, cost;
} tri[maxn];

struct Node {
    int type, id;
} node[maxn*2];
bool operator < (Node a, Node b) {
    if (a.type==0 && b.type==0) {
        return tri[a.id].l < tri[b.id].l;
    }
    else if (a.type==0 && b.type==1) {
        return tri[a.id].l < tri[b.id].r;
    }
    else if (a.type==1 && b.type==0) {
        return tri[a.id].r <= tri[b.id].l;
    }
    else {
        return tri[a.id].r < tri[b.id].r;
    }
}
int f[maxn];

int main() {
    int n, x; scanf("%d%d", &n, &x);

    int m = 0, m2=0;
    for (int i = 0; i < n; i++) {
        int l, r, c; scanf("%d%d%d", &l, &r, &c);
        if (r-l+1 >= x) continue;
        tri[m].l = l;tri[m].r=r+1;tri[m++].cost=c;
        node[m2].type=0;node[m2++].id=m-1;
        node[m2].type=1;node[m2++].id=m-1;
    }
    sort(node, node+m2);
    if (debug) for (int i = 0; i < m2; i++) {
        printf("第%d个: %d\n", i, node[i].id);
    }
    for (int i = 0; i < maxn; i++) {
        f[i] = inf;
    }
    ll ans = inf;

    for (int i = 0; i < m2; i++) {
        int tp = node[i].type, id=node[i].id;
        int cost = tri[id].cost, num = tri[id].r-tri[id].l;
        if (tp == 0) { // left
            ans = min(ans, (ll)cost+f[x-num]);
        }
        else { // right
            f[num] = min(f[num], cost);
        }
    }
    if (ans == inf) printf("-1\n");
    else printf("%d\n", (int)ans);

    return 0;
}