#include <bits/stdc++.h>
#define int LL 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b;i>=a;i--)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forenska(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define GREATER(x) x,vector<x>,greater<x>
#define randIn(L,R) (((LL)rand()*rand())%(R-L)+L)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vec;
typedef vector<LL> vecL;
typedef vector<pii> vecP;
typedef vector<pLL> vecPL;
typedef vector<string> vecS;
typedef vector<vec> mat;
typedef complex<double> point;
const long double PI=3.14159265358979323846264338327950;
const LL INFLL=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;
const long double EPS=1e-10;
int read()
{
    int x=0;
    char ch=' ';
    bool flag=false;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')flag=true;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return flag?-x:x;
}
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
const int MAX_N=105;
vec pre[4];
int v[MAX_N],w[MAX_N],n,W;
signed main()
{
	cin>>n>>W;
	rep(i,0,n)cin>>w[i]>>v[i];
	rep(i,0,n)
	{
		pre[w[i]-w[0]].pb(v[i]);
	}
	rep(i,0,4)sort(all(pre[i]));
	rep(i,0,4)pre[i].pb(0);
	rep(i,0,4)reverse(all(pre[i]));
	rep(i,0,4)
	{
		rep(j,1,pre[i].size())
		{
			pre[i][j]+=pre[i][j-1];
		}
	}
	int ans=0;
	rep(p0,0,pre[0].size())
	{
		rep(p1,0,pre[1].size())
		{
			rep(p2,0,pre[2].size())
			{
				int p3=(W-w[0]*p0-(w[0]+1)*p1-(w[0]+2)*p2)/(w[0]+3);
				if(p3<0)continue;
				if(p3>=pre[3].size())p3=pre[3].size()-1;
				if(W-w[0]*p0-(w[0]+1)*p1-(w[0]+2)*p2<0)continue;
				ans=max(ans,pre[0][p0]+pre[1][p1]+pre[2][p2]+pre[3][p3]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}