#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const int MOD = 998244353;
const int INF = 1000000007;
const LL LINF = 1LL * INF * INF; 
const int MAXN = 100007;
const LD EPS = 1e-12;

int A[MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int n, k = 0, x = 0;
	cin >> n;
	REP(i, n)
		cin >> A[i];
	sort(A, A + n);
	reverse(A, A + n);
	while (A[k + 1] > k + 1)
		++k;
	FOR(i, k, n)
		x += (A[i] > k);
	cout << ((A[k] - k) & x & 1 ? "Second" : "First");
	//cout << endl; system("pause");
	return 0;
}