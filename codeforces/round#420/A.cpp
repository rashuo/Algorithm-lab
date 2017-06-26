#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 50 + 10;
int arr[maxn][maxn], n;

bool Find(int val, int row, int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != col && j != row) {
                if (arr[row][i] + arr[j][col] == val) {
                    return true;
                }
            }    
        }
    }
    return false;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]!=1 && !Find(arr[i][j], i, j)) {
                ok = false;
            }
        }
    }
    if (ok) puts("Yes");
    else puts("No");

	return 0;
}