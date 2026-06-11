#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int parent[100001],edge[100001];
int find(int x){
	if(parent[x]<0)return x;
	return parent[x]=find(parent[x]);
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return;
	parent[a]+=parent[b];
	parent[b]=a;
}
int c[100001];
Vi v[100001];
bool bfs(int N)
{
	queue<int> q;
	q.push(N);
	c[N]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:v[x])
		{
			if(c[next]==-1)
			{
				c[next]=1-c[x];
				q.push(next);
			}
			else if(c[next]==c[x])return 1;
		}
	}
	return 0;
}
int main(){
	MEM_1(c);
	MEM_1(parent);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		merge(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ll c1=0,c2=0,r=0;
	fup(i,1,n,1)
		if(find(i)==i)
	{
		if(-parent[i]==1)r++;
		else if(bfs(i))c2++;
		else c1++;
	}
	printf("%lld",2*c1*c1+(c1+c2)*(c1+c2)-c1*c1+2*r*n-r*r);
}