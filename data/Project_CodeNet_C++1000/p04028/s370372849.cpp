#include<bits/stdc++.h>
using namespace std;
//#include<ext/rope>
//using namespace __gnu_cxx
//#include<ext/pb_ds/priority_queue.hpp>
//using namespace __gnu_pbds;
#define lowbit(x) (x&-x)
#define pb push_back
#define empb emplace_back
#define all(x) (x).begin(),(x).end()
#define clr(a,b) memset(a,b,sizeof(a))
#define caze(T) for(cin>>T;T;T--)
#define inf (1<<29)
#define Endl ('\n')
#define fi first
#define se second
#define db double
#define ldb long double
#define ll long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
inline char nc() {
	#define SZ 1000000
	static char buf[SZ], *p1, *p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline int scan(T &x) {
	char c, sign=1; 
	while(!isdigit(c=nc())&&c!=EOF)if(c=='-')sign*=-1;
	if(c==EOF) return EOF;
	for(x = 0; isdigit(c); c = nc())
		x = (x<<1) + (x<<3) + (c&15);
	return x *= sign, 1;
}
template<typename T, typename...Args>
inline int scan(T &x, Args&...args) {
	return scan(x), scan(args...);
}
const int N=5050;
const int mod=1000000007;
int dp[N][N];
char s[N];
void upd(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int main()
{
	int n,m;
	cin>>n>>s;
	m=strlen(s);
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		upd(dp[i][0],dp[i-1][0]);
		for(int j=1;j<=i;++j)
		{
			upd(dp[i][j-1],dp[i-1][j]);
			upd(dp[i][j],dp[i-1][j-1]);
			upd(dp[i][j],dp[i-1][j-1]);
		}
	}
	const int iv=(mod+1)/2;
	int ans=dp[n][m];
	for(int i=0;i<m;++i)
		ans=1LL*ans*iv%mod;
	cout<<ans<<Endl;
}