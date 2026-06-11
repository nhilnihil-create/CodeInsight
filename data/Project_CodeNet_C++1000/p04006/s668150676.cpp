#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <utility>
#include <assert.h>
#include <regex>
#include <numeric>
#include <functional>
#include <iomanip>
using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
#define INF (1LL << 48)

struct PT { ll x; ll y; };
string to_s(ull x) { return to_string(x); }
string to_s(ll x) { return to_string(x); }
ll to_ll(const string& x) { return stoll(x); }
ull to_ull(const string& x) { return stoull(x); }




int main(int argc, char* argv[])
{
	cout << std::fixed << std::setprecision(10);

	for (;;) {
		ll N, X;

		cin >> N >> X;
		if (cin.fail()) break;

		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		vector<int> S(N, INT_MAX);
		ll res = INF;
		for (ll i = 0; i < N; i++) {
			int old = S[N - 1];
			for (ll j = N - 1; j > 0; j--) {
				S[j] = S[j - 1];
			}
			S[0] = old;

			ll r = i * X;
			for (int j = 0; j < N; j++) {
				S[j] = min(S[j], A[j]);
				r += S[j];
			}
			res = min(res, r);
		}
		cout << res << endl;
	}

	return 0;
}
