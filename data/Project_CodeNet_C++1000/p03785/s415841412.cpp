#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    int n,c,k;
    cin>>n>>c>>k;
    int dp[n];
    int times[n];
    for(int i=0;i<n;i++)
    {
        cin>>times[i];
        dp[i]=INT_MAX;
    }
    dp[0]=1;
    sort(times,times+n);
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+1;
        int time=times[i]-k-1;
        int idx=upper_bound(times,times+n,time)-times;
        int cidx=i-c+1;
        int realidx=max(idx,cidx);
        if(realidx!=0)
        dp[i]=dp[realidx-1]+1;
        else
            dp[i]=1;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}