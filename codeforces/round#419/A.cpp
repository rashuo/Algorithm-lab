#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;

int sub(int a, int b, int c, int d, int aa, int bb, int cc, int dd) {
	int u = (aa*10+bb)*60 + (cc*10+dd);
	int v = (a*10+b)*60 + (c*10+d);
	return u - v;
}
int main() {
	int s1, s2;
	scanf("%d:%d", &s1,&s2);

	int a = s1/10, b = s1%10, c = s2/10, d = s2%10;

	if (b <= 5) {
		if (b*10+a >= c*10+d) {
			printf("%d\n", b*10+a-(c*10+d));
			if (debug) {
				printf("答案是: %d%d:%d%d\n", a,b,b,a);
			}
		}
		else {
			int aa = (a+(b+1)/6)%3, bb = (b+1)%6, cc = bb, dd = aa;
			if (a == 2 && b == 3) {
				aa = 2, bb = 4, cc = 0, dd = 0;
			}
			printf("%d\n", sub(a,b,c,d,aa,bb,cc,dd));
			if (debug) {
				printf("答案是: %d%d:%d%d\n", aa,bb,cc,dd);
			}
		}
	}
	else {
		int aa = (a+1)%3, bb = 0, cc = bb, dd = aa;
		printf("%d\n", sub(a,b,c,d,aa,bb,cc,dd));
			if (debug) {
				printf("答案是: %d%d:%d%d\n", aa,bb,cc,dd);
			}
	}

	return 0;
}