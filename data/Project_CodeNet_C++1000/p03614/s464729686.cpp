#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <utility>
#include <assert.h>
#include <regex>
#include <numeric>
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
	for (;;) {
		int N;
		cin >> N;
		if (cin.fail()) break;

		int ans = 0;
		bool swapped = false;
		for (int i = 1; i <= N; i++) {
			int p;
			cin >> p;
			if (!swapped && p == i) {
				ans++;
				swapped = true;
			} else {
				swapped = false;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
