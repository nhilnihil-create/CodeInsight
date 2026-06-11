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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

ll power(int x, int n)
{
	ll power = 1;
	for (int i = 0; i < n; i++) power *= x;
	return power;
}
int A[100010];
int main()
{
	int N, P;
	cin >> N >> P;
	ll even = 0, odd = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] % 2 == 0) even++;
		else odd++;
	}
	ll ans = 0;
	if (odd == 0) {
		if (P == 0) ans = power(2, N);
		else ans = 0;
	}
	else {
		ans = power(2, N - 1);
	}
	cout << ans << endl;
}