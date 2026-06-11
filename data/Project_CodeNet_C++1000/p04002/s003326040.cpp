#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
//int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,0,1,1,1,-1,-1,-1 }, dy[] = { 1,0,-1,1,0,-1,1,0,-1 };

set<Pi> S;
map<Pi, int> M;
ll cnt[10];
int main() {
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		S.insert(Pi(x, y));
	}
	set<Pi>::iterator it;
	for (it = S.begin(); it != S.end(); it++)
	{
		int x = it->X, y = it->Y;
		fup(i, 0, 8, 1)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx <= 1 || nx >= h || ny <= 1 || ny >= w)continue;
			if (M[Pi(nx, ny)])continue;
			int cnt = 0;
			fup(ii, 0, 8, 1)
			{
				int nnx = nx + dx[ii], nny = ny + dy[ii];
				if (S.find(Pi(nnx, nny)) != S.end())cnt++;
			}
			M[Pi(nx, ny)] = cnt;
		}
	}
	map<Pi, int>::iterator it2;
	for (it2 = M.begin(); it2 != M.end(); it2++)
	{
		cnt[it2->second]++;
	}
	cnt[0] = (1LL * (h - 2)*(w - 2) - M.size());
	fup(i, 0, 9, 1)printf("%lld\n", cnt[i]);
}