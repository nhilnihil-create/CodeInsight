#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dyn[1000100], ps[1000100];
ll MOD = 1000000007, n;

int main() {
    int i;
    dyn[0] = ps[0] = 1;
    scanf("%lld",&n);
    for (i=1;i<=n;i++) {
        dyn[i] = (dyn[i-1] + ((i>=3)?ps[i-3]:0))%MOD;
        ps[i] = (ps[i-1]+dyn[i])%MOD;
    }
    ll sum = 0;
    for (i=0;i<n-1;i++) {
        sum += (dyn[i]*(((n-1)*(n-1))%MOD+i+1))%MOD;
        sum %= MOD;
    }
    sum += (dyn[n-1]*(n-1))%MOD;
    sum += dyn[n];
    printf("%lld\n",sum%MOD);

    return 0;
}
