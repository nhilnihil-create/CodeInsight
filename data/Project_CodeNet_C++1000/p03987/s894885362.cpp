#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <set>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
const ll inf = (1LL << 60);
const ll mod = 1000000007;
ll max(ll a, ll b) {
	if (a < b)
		return b;
	else
		return a;

}
ll min(ll a, ll b) {
	if (a < b)
		return a;
	else
		return b;

}



int main() {
	ll N;

	cin >> N;
	vector<ll> A(N + 1), T(N + 1);
	rep(i, N) {
		cin >> A[i];
		T[A[i]] = i + 1;
	}

	set<ll> S, M;
	ll sum = 0;
	S.insert(0), S.insert(N + 1);
	M.insert(0), M.insert(-(N + 1));
	for (int i = 1; i <= N; i++) {

		auto it = S.lower_bound(T[i]);
		auto it2 = M.lower_bound(-T[i]);
		int a = *it;
		int b = -*it2;
		sum += i * (a - T[i]) * (T[i] - b);
		S.insert(T[i]);
		M.insert(-T[i]);
	}


	cout << sum << endl;

	return 0;
}