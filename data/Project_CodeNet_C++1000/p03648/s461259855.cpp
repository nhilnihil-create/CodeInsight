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
 * 4 4 4 4 4
 * 9 3 3 3 3
 * 8 8 2 2 2
 * 7 7 7 1 1
 * 6 6 6 6 1
 * 5 5 5 5 5
 * 10 4 4 4 4
 * 9 9 3 3 3
 * 8 8 8 2 2
 * 7 7 7 7 2
 * 6 6 6 6 6
 */
int main() {
	//const ll MAX = 10000000000001000;
	ll k;
	cin >> k;
	int n = 50;
	vector <ll> A(n);
	for (int i = 0; i < n; i++) {
		A[i] = n - 1 + k / n;
	}
	k = k % n;
	while (k > 0) {
		int pos = -1;
		ll mn = INF;
		for (int i = 0; i < n; i++) {
			if (mn > A[i]) {
				mn = A[i];
				pos = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (pos == i) {
				A[i] += n;
			}
			else {
				A[i] -= 1;
			}
		}
		k--;
	}
	cout << n << "\n";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
