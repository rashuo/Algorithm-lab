#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 50 + 10;

int main() {
    int c, v0, v1, a, l; scanf("%d%d%d%d%d", &c,&v0,&v1,&a,&l);

    int ans = 0, page = 0;

    while (page < c) {
        page += min(v0+a*ans,v1)-(ans==0?0:l);
        ans ++;
    }
    printf("%d\n", ans);

	return 0;
}