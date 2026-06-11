#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
#include <deque>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
using vi = vector<int>;
using vll = vector<ll>;
ll mod = 1e9 + 7;
ll llmax = 10000000000000000000ll;
using namespace std;
using Graph = vector<vector<int>>;
Graph G;
const int AMAX = 100000;
/*int cnt_digit(ll N)
{
	int digit = 0;

	while (N > 0)
	{
		N /= 10;
		digit++;
	}
	return digit;
}



int n;
vll a;

ll solve(bool isp)
{
	ll sum = 0ll;
	ll ret = 0ll;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (isp and sum <= 0)
		{
			ret += -sum + 1;
			sum = 1ll;
		}
		if (not isp and sum >= 0)
		{
			ret += sum + 1;
			sum = -1ll;
		}
		isp ^= 1;
	}
	return ret;
}

*/


/*
 * 最大公約数計算
 */
ll gcd(ll a, ll b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b)
{
	ll g = gcd(a, b);

	return a / g * b;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;

	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		int sa = b - a + 1;
		ans += sa;
	}
	
		cout << ans << endl;
	return 0;

}

