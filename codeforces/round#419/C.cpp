#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 100+10;
int arr[maxn][maxn], t = 0, sum = 0;

struct ANS {
    int no, times, type;
    ANS() {};
    ANS(int n, int tm, int tp):no(n),times(tm),type(tp){}
    void setValue(int n, int tm, int tp) {
        no = n;
        times = tm;
        type = tp;
    }
} ans[maxn+maxn];

void ite(int n, int m, int type) {
    if (type == 0) {
        for (int i = 0; i < n; i++) {
            int minv = 500;
            for (int j = 0; j < m; j++) {
                minv = min(minv, arr[i][j]);
            }
            for (int j = 0; j < m; j++) {
                arr[i][j] -= minv;
            }
            sum += minv;
            if (minv != 0)
                ans[t++].setValue(i+1, minv, 0);
        }
    }
    else {
        for (int j = 0; j < m; j++) {
            int minv = 500;
            for (int i = 0; i < n; i++) {
                minv = min(minv, arr[i][j]);
            }
            for (int i = 0; i < n; i++) {
                arr[i][j] -= minv;
            }
            sum += minv;
            if (minv != 0)
                ans[t++].setValue(j+1, minv, 1);
        }
    }
}
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    if (n <= m) {
        ite(n, m, 0);
        ite(n, m, 1);
    }
    else {
        ite(n, m, 1);
        ite(n, m, 0);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                ok = false;
            }
        }
    }
    if (!ok) {
        puts("-1");
    }
    else {
        printf("%d\n", sum);
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < ans[i].times; j++) {
                if (ans[i].type==0) printf("row");
                else printf("col");
                printf(" %d\n", ans[i].no);
            }
        }
    }


	return 0;
}