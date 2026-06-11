#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pie acos(-1)
#define loop(i,a,n) for(int i=a;i<n;i++)
#define trav(a,x) for(auto &a:x)
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define endl "\n"
#define debug(x)  cout<<#x<<" " <<x<<endl;
#define dbg(x,y)  cout<<#x<<" " <<x<<" "<<#y<<" "<<y<<endl;
#define all(v) v.begin(),v.end()
#define si(x) x.size()

const int e = 100005;
const ll INF = 1e18+5;
int n,a;
vi x(55);
ll dp[55][55][55*55];
ll ans(int i , int j , int k)// i is index  j is no. k is sum
{
    if(i==n+1)
    return 0;
    if(j==0 && k==0)
    return 1;
    ll &memo = dp[i][j][k];
    if(memo!=-1)
    return memo;
    memo=ans(i+1,j-1,k-x[i])+ans(i+1,j,k);
    return memo;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>a;
    loop(i,0,n)
    cin>>x[i];
    ll val=0;
    for(int i = 1 ; i <= n ; i++ )
    {
        ll sum = a*i;
        val+=ans(0,i,sum);
    }
    cout<<val;
}
int main() {
	// your code goes here
	io;
	//int t ;
	
    solve();
	return 0;
}
