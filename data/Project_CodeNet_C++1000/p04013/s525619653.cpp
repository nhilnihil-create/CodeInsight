#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll solve(int a[],int n,int s,int fl,ll dp[51][2501][2])
{
  ll cnt=0;
  if(s==0&&fl==1)
    cnt++;
  if(n==0)
    return cnt;
  if(dp[n][s][fl]!=-1)
    return dp[n][s][fl];
  ll x = solve(a,n-1,s+a[n],1,dp);
  ll y = solve(a,n-1,s,0,dp);
  dp[n][s][fl] = cnt+x+y;
  return dp[n][s][fl];
}
int main()
{
    flash;
    //sieve();
    int T=1,n,k,i,j;
    // cin>>T;
    while(T--)
    {
        cin>>n>>k;
        int a[n+1];
        ll dp[51][2501][2];
        FOR(i,0,51)FOR(j,0,2501)  dp[i][j][0]=dp[i][j][1]=-1;
        FOR(i,1,n+1){
          cin>>a[i];
          a[i] -= k;
        }
        ll cnt = solve(a,n,0,0,dp);
        cout<<cnt<<endl;
    }
}