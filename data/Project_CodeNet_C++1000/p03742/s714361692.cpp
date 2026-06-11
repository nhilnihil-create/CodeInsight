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
 * 4 8
 * 5 6
 * 1 8
 * 3 4
 * 1 5
 * 2 3
 * 0 4
 * 1 2
 * 
 */
int main() {
	ll a, b;
	cin >> a >> b;
	if (a <= 1 && b <= 1) {
		cout << "Brown";
		return 0;
	}
	if (a == b || a == b + 1 || a + 1 == b) {
		cout << "Brown";
	}
	else {
		cout << "Alice";
	} 
}
