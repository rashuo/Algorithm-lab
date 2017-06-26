#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;

long long solve(long long x, long long y) {
    return (x+1)*(y+1)*(x+y)/2;
}
int main() {
    int m, b; scanf("%d%d", &m, &b);

    long long ans = 0;
    for (int y = 0; y <= b; y++) {
        int x = m*(b-y);
        ans = max(ans, solve(x, y));
    }
    printf("%I64d\n", ans);

	return 0;
}