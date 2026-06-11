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
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;

	int size = s.size();
	char f = s.at(0);
	char l = s.at(size - 1);
	cout << f << size - 2 << l << endl;
	
	
	return 0;

	


}
