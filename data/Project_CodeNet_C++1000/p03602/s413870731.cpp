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

int main() {
	int n;
	cin >> n;
	vector<vector<int>> A(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int mn = MOD;
			for (int k = 0; k < n; k++) {
				if(k != i && k != j)
					mn = min(mn, A[i][k] + A[k][j]);
			}
			if(mn < A[i][j]) {
				cout << -1;
				return 0;
			}
			else if(mn > A[i][j]) {
				ans += A[i][j];
			}
		}
	}
	cout << ans / 2;
}
