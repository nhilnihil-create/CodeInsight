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
const int MAX_N=300005;
int n;
int pre[MAX_N*3];
int rev[MAX_N*3];
int a[MAX_N*3];
signed main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin>>n;
	For(i,1,3*n)cin>>a[i];
	priority_queue <GREATER(int)> q1;
	For(i,1,3*n)
	{
		pre[i]=pre[i-1]+a[i];
		q1.push(a[i]);
		if(q1.size()>n)
		{
			pre[i]-=q1.top();
			q1.pop();
		}
	}
	priority_queue <int> q2;
	per(i,3*n,1)
	{
		rev[i]=rev[i+1]+a[i];
		q2.push(a[i]);
		if(q2.size()>n)
		{
			rev[i]-=q2.top();
			q2.pop();
		}
	}
	int ans=-LONG_LONG_MAX;
	For(i,n,2*n)
	{
		ans=max(ans,pre[i]-rev[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
