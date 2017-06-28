#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const double eps = 1e-8;

double mabs(double s) {
    return s > 0 ? s : -s;
}
bool smaller(double a, double b) {
    if (mabs(b-a) < eps) return true;
    return a < b;
}
int main() {
    int n, a; scanf("%d%d", &n, &a);

    double l = 180.0/n;
    double r = 180-360.0/n;

    int times = 1; double ans = 360;
    int ansd = 1;

    while (smaller(times*l, r)) {
        if (ans > mabs(times*l-a)) {
            ans = mabs(times*l-a);
            ansd = times;
        }
        times++;
    }
    printf("2 1 %d\n", 2+ansd);

	return 0;
}