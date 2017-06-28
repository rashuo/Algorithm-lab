#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = true;
const int maxn = 3e5 + 10;
int stack[maxn];

int main() {
    int n; scanf("%d", &n);
    int top = -1, t = 1, ans = 0;

    for (int i = 0; i < 2*n; i++) {
        char s[10]; int v; scanf("%s", s);
        if (s[0] == 'a') {
            scanf("%d", &v);
        }
        if (s[0] == 'a') {
            stack[++top] = v;
        }
        else {
            if (top == -1) {
                t++;
            }
            else {
                if (stack[top] == t) {
                    t++;
                    top--;
                }
                else {
                    top = -1;
                    t++;
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);

	return 0;
}