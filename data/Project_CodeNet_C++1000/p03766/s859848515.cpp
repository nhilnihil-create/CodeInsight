#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int dp[1011111];
int S[1011111];

int sum(int l, int r)
{
	int ans=0;
	if(l<0) ans=abs(l),l=0;
	if(l==0) return add(ans,S[r]);
	else return add(ans,add(S[r],MOD-S[l-1]));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	dp[0]=1; dp[1]=n; S[0]=1; S[1]=add(n,1);
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		dp[i]=add(dp[i],mult(n-1,n-1));
		dp[i]=add(dp[i],sum(i-(n+1),i-3));
		S[i]=add(S[i-1],dp[i]);
		//cerr<<i<<' '<<dp[i]<<'\n';
	}
	cout<<dp[n]<<'\n';
}
