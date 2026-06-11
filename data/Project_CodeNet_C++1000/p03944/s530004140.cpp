#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using str = string;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
const double PI = 3.141592653589793238;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i, m, n) for (int i = m; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greator<>()
#define d20 std::setprecision(20)
#define veci vector<int>
#define vecll vector<long long int>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}
void comb(vector<vector<long long int>> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int k = 1; k < v.size(); k++)
	{
		for (int j = 1; j < k; j++)
		{
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
		}
	}
}
bool is_not_out_of_range(size_t now, size_t max_num)
{
	return !(now < 0 || max_num <= now);
}
ll repeat_squaring(ll n, ll p, ll m)
{
	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		ll t = repeat_squaring(n, p / 2, m);
		return t * t % m;
	}
	return n * repeat_squaring(n, p - 1, m);
}

int main()
{
	int w, h, n;
	cin >> w >> h >> n;
	vector<vector<bool>> area(h, vector<bool>(w, true));
	rep(i, n)
	{
		int x, y, a;
		cin >> x >> y >> a;
		switch (a)
		{
		case 1:
			rep(i, h)
			{
				rep(j, x)
				{
					area[i][j] = false;
				}
			}
			break;
		case 2:
			rep(i, h)
			{
				REP(j, x, w)
				{
					area[i][j] = false;
				}
			}
			break;
		case 3:
			rep(i, y)
			{
				rep(j, w)
				{
					area[i][j] = false;
				}
			}
			break;
		case 4:
			REP(i, y, h)
			{
				rep(j, w)
				{
					area[i][j] = false;
				}
			}
			break;
		default:
			break;
		}
	}
	int ans = 0;
	rep(i, h)
	{
		rep(j, w)
		{
			ans += area[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}