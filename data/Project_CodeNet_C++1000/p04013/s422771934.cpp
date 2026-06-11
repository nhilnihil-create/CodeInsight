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
int arr[50],n,a;
ll dp[55][55][2600];
ll recur(int pos,int sum,int cnt)
{
    if(pos==n)
    {

        if(cnt==0)
            return 0;
        int cur=sum/cnt;
        if(cur*cnt!=sum)
        return 0;
        if(cur==a)
            return 1;
        return 0;
    }
    ll &ret=dp[pos][cnt][sum];
    if(~ret)
        return ret;
    ret=0;
    ret+=recur(pos+1,sum,cnt);
    ret+=recur(pos+1,sum+arr[pos],cnt+1);

    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>a;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,0)<<endl;




    return 0;
}
