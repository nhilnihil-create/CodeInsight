#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

int		main(void)
{
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	int SW = 100*A, S = 0;
	double e = (double)100*E/(E+100);
	A *= 100; B *= 100;
	for (int i = 0; A*i <= F; i++)
	{
		for (int j = 0; A*i+B*j <= F; j++)
		{
			int W = (A*i+B*j);
			for (int k = 0; W+C*k <= F; k++)
			{
				for (int l = 0; W+C*k+D*l <= F; l++)
				{
					int s = C*k+D*l;
					double P1 = (double)100*S/(SW);
					double P2 = (double)100*s/(W+s);
					if (P2 <= e && P1 < P2)
					{
						SW = W+s;
						S = s;
					}
				}
			}
		}
	}
	cout << SW << " " << S << endl;
}

