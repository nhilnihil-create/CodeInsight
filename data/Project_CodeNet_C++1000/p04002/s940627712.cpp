#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 100100;

PII A[MAX];

LL RES[MAX];

int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);

	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);

	set<PII> S;

	FOR (i, 0, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		S.insert(MP(x, y));
		A[i] = MP(x, y);
	}

	FOR (it, 0, n)
	{
		int x = A[it].first;
		int y = A[it].second;

		FOR (a, 0, 3)
		{
			FOR (b, 0, 3)
			{
				if (x - a < 0) continue;
				if (y - b < 0) continue;

				if (x + 2 - a >= h) continue;
				if (y + 2 - b >= w) continue;

				int cnt = 0;

				FOR (i, 0, 3)
				{
					FOR (j, 0, 3)
					{
						int x1 = x - a + i;
						int y1 = y - b + j;

						if (S.count(MP(x1, y1))) cnt++;
					}
				}

				RES[cnt]++;
			}
		}
	}

	LL tot = 0;

	FOR (i, 1, 10)
	{
		RES[i] /= i;
		tot += RES[i];
	}

	RES[0] = (h - 2) * (LL)(w - 2) - tot;

	FOR (i, 0, 10)
	{
		cout<<RES[i]<<endl;
	}



}
