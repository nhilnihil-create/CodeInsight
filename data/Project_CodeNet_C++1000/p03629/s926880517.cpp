
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll N = 200030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    998244353;
string s;
int n;
int dp[2<<17][30];
int main()
{  fast
cin>>s;
n=s.size();
for(int i=s.size();i--;)
{
	int mx=1e9;
	for(int j=0;j<26;j++)
	{

	if(mx>dp[i+1][j])
	mx=dp[i+1][j];
	dp[i][j]=dp[i+1][j];
}
dp[i][s[i]-'a']=mx+1;
}
int idx=0;
string ans="";
while(idx<n)
{
	int mn=0;
	for(int i=0;i<26;i++)
	if(dp[idx][i]<dp[idx][mn])mn=i;
	ans+=char(mn+'a');
	while(idx<n&&s[idx]!=char(mn+'a'))idx++;
	idx++;
}
cout<<ans;
}


