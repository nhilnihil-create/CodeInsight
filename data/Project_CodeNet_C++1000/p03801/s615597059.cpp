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
#define INF 987654321
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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

set<iii> S;
Pi p[100000];
ll ans[100000];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d",&p[i].X);
		p[i].Y=i;
	}
	sort(p,p+n);
	int a=p[0].X,id=p[0].Y,cnt=1;
	fup(i,1,n-1,1)
	{
		if(p[i].X==a)
		{
			id=min(id,p[i].Y);
			cnt++;
		}
		else
		{
			S.insert(iii(-a,id,cnt));
			a=p[i].X,id=p[i].Y,cnt=1;
		}
	}
	S.insert(iii(-a,id,cnt));
	while(!S.empty())
	{
		if(S.size()==1)
		{
			int aa,ii,cc;
			tie(aa,ii,cc)=*S.begin();
			aa*=-1;
			ans[ii]+=1LL*aa*cc;
			break;
		}
		auto it1=S.begin();
		auto it2=it1;
		it2++;
		int a1,i1,c1,a2,i2,c2;
		tie(a1,i1,c1)=*it1;
		tie(a2,i2,c2)=*it2;
		a1*=-1,a2*=-1;
		S.erase(it1);
		S.erase(it2);
		ans[i1]+=1LL*(a1-a2)*c1;
		c2+=c1;
		i2=min(i2,i1);
		S.insert(iii(-a2,i2,c2));
	}
	fup(i,0,n-1,1)printf("%lld\n",ans[i]);
}