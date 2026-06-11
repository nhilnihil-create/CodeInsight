#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
//#define X first
#define Y second
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LL MOD = 1000000007;
const LL INF = 1e9;
const LL LINF = INF * INF;
const LL MAXN = 507;

int x, A[MAXN * MAXN];
bool F[MAXN * MAXN], flag = true;

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("In.txt", "r", stdin);
	int n;
	cin >> n;
	FOR(i, 1, n + 1)
	{
		cin >> x;
		A[x] = i;
		F[x] = true;
	}
	int p = 1;
	FOR(i, 1, n * n + 1)
	{
		if (F[i])
		{
			REP(j, A[i] - 1)
			{
				while (A[p] && p < i) ++p;
				if (p == i) flag = false;
				A[p] = A[i];
			}
		}
	}
	p = n * n;
	RFOR(i, n * n + 1, 1)
	{
		if (F[i])
		{
			REP(j, n - A[i])
			{
				while (A[p] && p > i) --p;
				if (p == i) flag = false;
				A[p] = A[i];
			}
		}
	}
	if (flag)
	{
		cout << "Yes\n";
		FOR(i, 1, n * n + 1) cout << A[i] << ' ';
	}
	else cout << "No\n";
	//cout << endl; system("pause");
	return 0;
}