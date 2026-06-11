#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) (x & (-x))
#define BIT(a,b) ((ll)(a&(1<<b))==0 ? false : true)

const ll MAXN=1e6+10;
const ll Mod=1e9+7;

ll dp[MAXN];
ll partial[MAXN];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;

    dp[0]=n;
    partial[0]=n;

    for(ll i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+(n-1)*(n-1)+(i>2 ? partial[i-3] + n-i+1 : n-1);
        dp[i]%=Mod;

        partial[i]=partial[i-1]+dp[i];
        partial[i]%=Mod;
    }

    cout<<dp[n-1];
}
