#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 100100;

int A[MAX];
int D[MAX];

int AA[MAX];
int DD[MAX];

int RES[MAX];
int R[MAX];

VI solve(int n, int m, int t)
{
	FOR (i, 0, n)
	{
		int d = t;
		if (D[i] == 1) d = -d;
		RES[i] = A[i] + d;
		RES[i] %= m;
		if (RES[i] < 0) RES[i] += m;
	}

	LL tot = 0;

	int x = A[0];
	FOR (i, 1, n)
	{
		if (D[i] == D[0]) continue;
		int y = A[i];

		int dst = 0;

		if (D[i] == 1) dst = y - x;
		else dst = m - (y - x);

		LL cur = 0;

		int v = 2 * t;

		v -= dst;

		if (v <= 0) continue;
		cur = 1;
		cur += v / m;
		if (v % m == 0) cur--;

		tot += cur;
	}

	tot %= n;

	if (D[0] == 1) tot = n - tot;
	tot %= n;

	int ind = tot;
	int val = RES[0];
	int dir = D[0];

//	cout<<ind<<' '<<val<<' '<<dir<<endl;

	sort(RES, RES + n);

	int wh = -1;

	FOR (i, 0, n)
	{
		if (RES[i] == val)
		{
			if (dir == 1 && i < n && RES[i+1] == val) i++;
			wh = i;
			break;
		}
	}

	FOR (i, ind, n)
	{
		R[i] = RES[wh];
		wh++;
		if (wh >= n) wh -= n;
	}

	FOR (i, 0, ind)
	{
		R[i] = RES[wh];
		wh++;
		if (wh >= n) wh -= n;
	}

	VI res;
	FOR (i, 0, n)
	{
		res.PB(R[i]);
	}
	return res;
}

VI brute(int n, int m, int t)
{
	FOR (i, 0, n)
	{
		A[i] *= 2;
	}
	m *= 2;
	t *= 2;

	FOR (it, 0, t)
	{
		FOR (i, 0, n)
		{
			if (D[i] == 0) A[i]++;
			else A[i]--;
			A[i] %= m;
			if (A[i] < 0) A[i] += m;
		}

		FOR (i, 0, n)
		{
			int i1 = i;
			int i2 = (i+1) % n;
			if (A[i1] == A[i2])
			{
				D[i1] ^= 1;
				D[i2] ^= 1;
			}
		}
	}

	VI res;
	FOR (i, 0, n)
	{
		res.PB(A[i] / 2);
	}

	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	while(true)
	{
		int n, m, t;
		scanf("%d%d%d", &n, &m, &t);
		//n = 3;
		//m = 10;
		//t = 7;
		set<int> s;
		FOR (i, 0, n)
		{
			int x, d;
			scanf("%d%d", &x, &d);
			//x = rand() % m;
			//while(s.count(x)) x = rand() % m;
			//s.insert(x);
			//d = rand() % 2 + 1;
			d--;

			A[i] = x;
			D[i] = d;

			AA[i] = x;
			DD[i] = d;
		}

		//sort(A, A+n);
		//sort(AA, AA+n);

		VI a = solve(n, m, t);
	/*	VI b = brute(n, m, t);

		if (a != b)
		{
			cout<<n<<' '<<m<<' '<<t<<endl;
			FOR (i, 0, n)
			{
				cout<<AA[i]<<' '<<DD[i]<<endl;
			}

			FOR (i, 0, SZ(a))
			{
				cout<<a[i]<<' ';
			}
			cout<<endl;
			FOR (j, 0, SZ(b))
			{
				cout<<b[j]<<' ';
			}
			cout<<endl;
			throw -1;
		}
		else cout<<"ok"<<endl<<endl;*/


		FOR (i, 0, n)
		{
			printf("%d\n", R[i]);
		}
		break;
	}

}
