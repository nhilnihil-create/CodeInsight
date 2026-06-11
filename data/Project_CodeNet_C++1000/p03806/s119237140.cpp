#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define all(x) (x).begin(),(x).end()
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define trace(x) cerr<<#x<<"is "<<x<<'\n';

const int mod = 1e9+7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

int dp[49][409][409];
int a[49],b[49],c[49];

void solve()
{
	int n,ma,mb,i,j,k;
	cin>>n>>ma>>mb;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	memset(dp, infi , sizeof dp);
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=400;j++)
		for(k=0;k<=400;k++)
		{
			if(dp[i-1][j][k]==infi) continue;
			dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
			dp[i][j+a[i]][k+b[i]]=min(dp[i][j+a[i]][k+b[i]],dp[i-1][j][k]+c[i]);
		}
	}
	int ans=infi;
	for(j=1;j<=400;j++)
	for(k=1;k<=400;k++)
	if(j*mb==k*ma)
	ans=min(ans,dp[n][j][k]);
	if(ans==infi) cout<<-1;
	else cout<< ans;
}

int main()
{
	IOS
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
