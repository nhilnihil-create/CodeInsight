#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
/// ye tec khaphan ke yadam bemone : age jayi didi soale masir hamiltoni mikhad rasasho bokon yal oilery;
/// age ye ja mikhasti to dp az ozv i k ta entekhab koni bejash ye log bezan (nominal) hamoon 2**k va o 1 ent kon

///\\\///\\\///\\\\\\\\\\\\\\\\\///\\\///\\\///

const int N=5100,mod=1e9+7;
ll dp[N][N];

ll power(ll n, ll k)
{
    if (k==0)
    {
        return 1;
    }
    else
    {
        if (k%2==0)
        {
            ll x=power(n,k/2);
            return x*x%mod;
        }
        else
        {
            ll x=power(n,k/2);
            x=x*x%mod;
            return x*n%mod;
        }
    }
}
int32_t main()
{
    sync;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    dp[0][0]=1;
    for (int i=0; i<N-2; i++)
    {
        for (int j=0; j<N-2; j++)
        {
            // cout << i << " " << j << endl;
            if (j==0)
            {
                dp[i+1][j]+=dp[i][j];
                dp[i+1][1]+=dp[i][j]*2;
                dp[i+1][j]%=mod;
                dp[i+1][j+1]%=mod;
            }
            else
            {
                dp[i+1][j-1]+=dp[i][j];
                dp[i+1][j+1]+=dp[i][j]*2;
                dp[i+1][j-1]%=mod;
                dp[i+1][j+1]%=mod;
            }

        }
    }
    ll z=power(2,s.size());

    cout << dp[n][s.size()]*power(z,mod-2)%mod;


}
















