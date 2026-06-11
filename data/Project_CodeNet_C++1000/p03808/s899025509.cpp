
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
double max(double a, double b) {
	if (a < b) return b;

	return a;
}




vector<ll> A;
int main() {
	ll N;
	cin >> N;
	A.resize(N);
	ll K = 0;
	rep(i, N) {
		cin >> A[i];
		K += A[i];
	}

	if (K % (N * (N + 1) / 2) != 0 || K < (N * (N+1))/2) {
		cout << "NO" << endl;
		return 0;
	}

	K /= (N * (N + 1) / 2);

	ll sum = 0;
	rep(i, N - 1) {
		if ((K - (A[i + 1] - A[i])) >= 0 && (K - (A[i + 1] - A[i])) % N == 0) {
			sum += (K - (A[i + 1] - A[i])) / N;
			continue;
		}

		else {
			cout << "NO" << endl;
			return 0;
		}
			
		
	}

	if (sum <= K) {
		cout << "YES" << endl;
	}

	else {
		cout << "NO" << endl;
	}

	return 0;
}