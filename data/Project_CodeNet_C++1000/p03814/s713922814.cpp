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
#define vecb vector<bool>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}

int main()
{
	str s;
	cin >> s;
	int start, end;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A')
		{
			start = i;
			break;
		}
	}
	for (int i = s.size(); i >= 0; i--)
	{
		if (s[i] == 'Z')
		{
			end = i;
			break;
		}
	}
	cout << end - start + 1 << endl;

	return 0;
}