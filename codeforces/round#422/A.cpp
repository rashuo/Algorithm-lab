#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 50 + 10;

int main() {
    int a, b; scanf("%d%d", &a, &b);

    int v = min(a, b);

    int res = 1;

    for (int i = 1; i <= v; i++) {
        res *= i;
    }
    printf("%d\n", res);

    return 0;
}