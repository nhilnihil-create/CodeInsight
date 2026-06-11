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

const int MAX = 555;
const int MX = 1000000000;

int A[MAX][MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	int n1, m1;

	scanf("%d%d%d%d", &n, &m, &n1, &m1);

	if (n % n1 == 0 && m % m1 == 0)
	{
		cout<<"No"<<endl;
		return 0;
	}

	FOR (i, 0, n)
	{
		FOR (j, 0, m)
		{
			if ((i + 1) % n1 == 0 && (j + 1) % m1 == 0)
			{
				A[i][j] = -MX;
			}

			if (m % m1 != 0)
			{
				if ((i + 1) % n1 == 0 && j % m1 == 0) A[i][j] = MX - 1;
			}
			else
			{
				if (i % n1 == 0 && (j + 1) % m1 == 0) A[i][j] = MX - 1;
			}
		}
	}

	LL sum = 0;
	FOR (i, 0, n)
	{
		FOR (j, 0, m)
		{
			sum += A[i][j];
		}
	}


/*	FOR (i, 0, n)
	{
		FOR (j, 0, m)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}*/\

	if (sum > 0)
	{
		printf("Yes\n");
		FOR (i, 0, n)
		{
			FOR (j, 0, m)
			{
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("No\n");
	}
}
