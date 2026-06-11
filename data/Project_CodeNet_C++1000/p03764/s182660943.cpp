//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int n,m,x[N],y[N];
ll ans,cum,dif;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;++i) cin >> x[i];
    for(int i=0;i<m;++i) cin >> y[i];

    sort(x,x+n);
    sort(y,y+m);

    for(int i=0;i<n;++i) {

        dif = (dif + (1LL*x[i]*i - 1LL*x[i]*(n-1-i))%mod)%mod;

    }

    for(int i=0;i<m;++i) {

        ans = (ans+(((1LL*y[i]*i - cum)%mod)*dif)%mod)%mod;
        cum = (cum+y[i])%mod;

    }

    cout << ans << '\n';

    return 0;

}