#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
typedef vector<ll> vi;
typedef queue<ll> qi;
typedef queue<char> qc;
typedef queue<string> qs;
typedef vector<char> vc;
typedef vector<string> vs;
typedef map<char,ll> mpci;
typedef map<ll,ll> mpii;
typedef map<string,ll> mpsi;
typedef set<ll> sei;
typedef set<char> sec;
typedef set<string> ses;
typedef stack<ll> si;
typedef stack<char> sc;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pll> vpll;
typedef vector<pdd> vdd;
typedef unsigned int uint;
typedef long double ld;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;
/*=====================================================================*/
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define all(s) (s).begin(),(s).end()
#define fi first
#define se second
#define be begin
#define en end
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define forn(i,p,n) for(int i=p;i<n;i++)
#define ford(i,p,n) for(int i=n-1;i>=p;i--)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define zero(a) memset(a,0,sizeof(a))
#define number(a,num) memeset(a,num,sizeof(a))

/*=====================================================================*/

inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
inline void write(long long x) {
  static long long sta[35];
  long long top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
  puts("");
}
/*======================================================================*/
bool prime(int n)
{
	if(n==0||n==1)
	  return false;
	for(int i=2;i*i<=n;i++)
	  if(n%i==0)
	    return false;
	return true;
}
/*======================================================================*/
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
vector<int> v[111111];
int dist[2][111111];
int n;
/*======================================================================*/
void dfs(int m,int p,int c)
{
	dist[c][m]=dist[c][p]+1;
  	rep(i,v[m].size())
  	{
  	  if(v[m][i]!=p)
	  {
		dfs(v[m][i],m,c);
	  }	
	}
}
int main()
{
  /*
	ios_base::sync_with_stdio(0);
	cin(tie);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  */
  /*====================================================================*/
  read(n);
  rep(i,n-1)
  {
  	int a,b;
  	read(a);
  	read(b);
  	v[a].pb(b);
  	v[b].pb(a);
  }
  dist[0][0]=-1;
  dist[1][0]=-1;
  dfs(1,0,0);
  dfs(n,0,1);
  int cnt1=0,cnt2=0;
  for(int i=1;i<=n;i++)
  {
  	if(dist[0][i]<=dist[1][i])
  	  cnt1++;
  	else
  	  cnt2++;
  }
  if(cnt1>cnt2)
    cout<<"Fennec";
  else
    cout<<"Snuke";
  return 0;
}
