#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const bool debug = false;
const int maxn = 5e6+10;
const int mod = 1e9+7;
typedef long long ll;
ll d[maxn], f[maxn];

ll Mod(ll x) {
    return x%mod;
}
void init(int n) {
    d[2] = 1;

    for (int i = 2; i <= n; i++) {
         f[i] = i;
    }
    for (int i = 2; i*i <= n; i++) {
        for (int j = i*i; j<=n; j+=i) {
            f[j] = min((ll)i, f[j]);
        }
    }

    for (int i = 3; i <= n; i++) {
        bool find = false;
        if (f[i] == i) {
            d[i] = Mod((ll)i*(i-1)/2);
        }
        else {
            d[i] = Mod(Mod((ll)d[f[i]]*(i/f[i]))+d[i/f[i]]);
        }
        // for (int j = 2; j <= sqrt(i); j++) {
        //     if (i%j == 0) {
        //         d[i] = Mod(Mod((ll)d[j]*(i/j))+d[i/j]);
        //         find = true;
        //         break;
        //     }
        // }
    }
}
ll ksm(ll v, int n) {
    ll res = 1;
    
    while (n) {
        if (n&1) {
            res = Mod(res*v);
        }
        n >>= 1;
        v = Mod((ll)v*v);
    }
    return res;
}
ll solve(int t, int k, int l) {
    return Mod(ksm(t,k)*d[l+k]);
}
int main() {
    int t, l, r; scanf("%d%d%d", &t, &l, &r);

    init(r);

    ll ans = 0;
    ll fac = 1;
    for (int i = 0; i < r-l+1; i++) {
        // ans = Mod(ans+solve(t, i, l));
        ans = Mod(ans+Mod(fac*d[l+i]));
        fac = Mod(fac*t);
    }
    printf("%d\n", (int)ans);

	return 0;
}