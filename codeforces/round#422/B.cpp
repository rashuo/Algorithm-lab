#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 1000 + 10;
char s1[maxn], s2[maxn];
int n, m, k, ans[maxn];

int comp(int st) {
    int ret = 0;
    for (int i = st; i < st+n; i++) {
        if (s1[i-st] != s2[i]) {
            ret++;
        }
    }
    return ret;
}
int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s1, s2);
    k = n+1;

    for (int st = 0; st < m-n+1; st++) {
        int now = comp(st);
        if (k > now) {
            k = now;
            int cnt = 0;
            for (int i = st; i < st+n; i++) {
                if (s1[i-st] != s2[i]) {
                    ans[cnt++] = i-st+1;
                }
            }
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        if (i!=0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}