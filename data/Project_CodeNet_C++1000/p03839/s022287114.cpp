#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 400005
#define OFF 100001
using namespace std;

ll n,k,s[Nmax],s2[Nmax],x;
int main()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> x;
        s[i] = s[i-1] + max(0LL,x);
        s2[i] = s2[i-1] + x;
    }
    ll ans = 0;
    for (int i=k;i<=n;i++){
        ans = max(ans, s[i-k] + s[n] - s[i] + max(0LL,s2[i] - s2[i-k]));
    }

    cout << ans << '\n';

    return 0;
}
