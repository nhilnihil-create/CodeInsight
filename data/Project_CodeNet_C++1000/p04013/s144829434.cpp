// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll  long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define bp __builtin_popcountll
#define MOD 1000000007
const int N = 55;
 
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll dp[N][N][2505];
ll a[N];
ll n,k;
ll solve(ll index,ll total,ll sum)
{
    if(index==n)
    {
        if(total!=0 && sum%total==0)
        {
            if(sum/total==k)  return 1;
            else return 0;
        }
        else   return 0;
    }
    ll ans = dp[index][total][sum];
    if(ans!=-1)   return ans;
    ans = 0;
    ans += solve(index+1,total+1,sum+a[index]);
    ans += solve(index+1,total,sum);
    return dp[index][total][sum] = ans;
}
int main() 
{
    FAST;
    cin >> n >> k;
    for(ll i=0;i<n;i++)   cin >> a[i];
    memset(dp,-1,sizeof(dp));
    ll ans = solve(0,0,0);
    cout<<ans;
    
}    