#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=2e3+5;
int dp[N];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++) dp[i]=1e17;
	int ans1=1e18;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int k=(j-i);
			k=(k+n)%n;
			dp[j]=min(dp[j],a[k]);
		}
		int ans=i*x;
		for(int j=0;j<n;j++)
		{
			ans+=dp[j];
		}
		ans1=min(ans1,ans);
	}
	cout<<ans1;
}
// Don't be afraid to fail. Be afraid not to try.
// "Become grindian instead of greendian" - aryanc403
// When you want to succeed as bad as you want to breathe, only then you’ll Be Successful!
// No Matter,How Fast You Are Driving If You Are Driving in a Wrong Direction You Will Never Reach Your Destination
// When failures hit you, you hit the failures back with Bounce Back!
// When you face failures, Don’t change your goal, Change your strategy!