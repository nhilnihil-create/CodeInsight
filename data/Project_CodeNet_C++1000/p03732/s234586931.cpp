#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll dp[105][105][400],n,w,cost[105],weight[105];
ll recur(int pos,int taken,int k)
{
    if(weight[0]*taken+k>w)
        return INT_MIN;
    if(pos==n)
        return 0;
    ll &ret=dp[pos][taken][k];
    if(ret!=-1)
        return ret;
    ret=max(recur(pos+1,taken,k),recur(pos+1,taken+1,k+weight[pos]-weight[0])+cost[pos]);
    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    for(int i=0; i<n; i++)
        cin>>weight[i]>>cost[i];
    cout<<recur(0,0,0)<<endl;


    return 0;
}
