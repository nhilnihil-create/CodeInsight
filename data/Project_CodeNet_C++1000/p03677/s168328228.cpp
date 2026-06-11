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
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 1
 * All of them are independent and the last state only matters
 * If we have only 2 states we should try fixing the button as the 2nd state
 * Say if we have 3 states
 * 1 3 10 -> 10
 * 1 3 4 -> 3
 * 2 4 9 . 3 5 8 9 . 1 2 7
 * We'll traverse the sequence and if cur > prev
 * 1 2 3 4 5 6 7 8
 * - 1 - - 1
 * add 1 to c[prev + 1] and -1 to c[cur + 1] and -(cur - prev) to A[cur + 1]
 * if cur < prev
 * add 1 to c[prev + 1] and add (m - prev + 1) to A[1] 
 * and 1 to c[1] and -1 to c[cur + 1] and -dist(prev, cur) to A[cur + 1]
 */
int main() {
	int n, m;
	cin >> n >> m;
	int prev = -1;
	vector <ll> A(m + 2), c(m + 2);
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		int cur;
		cin >> cur;
		if (i > 1) {
			if (cur > prev) {
				c[prev + 1] += 1;
				c[cur + 1] -= 1;
				A[cur + 1] -= (cur - prev);
				total += (cur - prev);
			}
			else {
				c[prev + 1] += 1;
				A[1] += (m - prev);
				c[1] += 1;
				c[cur + 1] -= 1;
				A[cur + 1] -= (m - prev) + cur;
				total += (m - prev) + cur;
			}
		}
		prev = cur; 
	}
	for (int i = 1; i <= m; i++) {
		c[i] += c[i - 1];
		A[i] += (A[i - 1] + c[i]);
		//cout << A[i] << " ";
	}
	ll mx = 0;
	for (int i = 1; i <= m; i++) {
		mx = max(mx, A[i] - c[i]);
	}
	cout << total - mx;
}
