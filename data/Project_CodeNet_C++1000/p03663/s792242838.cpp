#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

/*
 * We are to guess an integer n
 * 1	Yes for sure
 * 10	If I get a no it has to be from 2 to 9 else it can be 1 or >= 10
 */
const ll N = 1LL * 100000 * 100000;
int main() {
	ll i = 10;
	char ch;
	while(true) {
		cout << "? " << i << endl;
		cin >> ch;
		if (ch == 'Y') {
			i *= 10;
		}
		else {
			ll lo = i / 10 + 1, hi = i - 1, ans = -1;
			while(lo <= hi) {
				ll mid = (lo + hi) / 2;
				cout << "? " << mid * 10 << endl;
				cin >> ch;
				if (ch == 'Y') {
					ans = mid;
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			cout << "! " << ans << endl;
			return 0;
		}
		if (i == N) {
			break;
		}
	}
	while(i > 1) {
		cout << "? " << i - 1 << endl;
		cin >> ch;
		if (ch == 'N') {
			cout << "! " << i << endl;
			return 0;
		}
		i /= 10;
	}
	cout << "! " << 1 << endl;
}
