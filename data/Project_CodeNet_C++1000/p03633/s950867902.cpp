#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll gcd(ll a, ll b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a * (b / gcd(a, b));
}
int main()
{
	int N;
	cin >> N;
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		ll T;
		cin >> T;
		ans = lcm(ans, T);
	}
	cout << ans << endl;
}
