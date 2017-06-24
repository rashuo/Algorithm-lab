#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 2e5+10;
int l[maxn], r[maxn], num[maxn];

int main() {
    int n, k, q; scanf("%d%d%d", &n, &k, &q);

    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));

    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        l[a]++; r[b]++;
    }
    int x = 0;
    for (int i = 1; i <= 2e5; i++) {
        x += l[i];
        num[i] += x;
        x -= r[i];
        num[i] = num[i] >= k ? 1: 0;
        num[i] += num[i-1];
    }
    while(q--) {
        int a, b; scanf("%d%d", &a, &b);
        printf("%d\n", num[b]-num[a-1]);
    }


	return 0;
}