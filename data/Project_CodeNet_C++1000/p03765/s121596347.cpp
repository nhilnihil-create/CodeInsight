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
 * A
 * BB
 * AAB, BAA
 * BBABB, ABBBB
 * At one point any string could be made one of A, B, {}
 * If you say that both the strings could be made equal 
 * then you can go on making the strings one of the above chars
 */
int main() {
	string s, t;
	cin >> s >> t;
	int n = (int) s.size();
	int m = (int) t.size();
	vector <int> c1(n + 1), c2(m + 1);
	for (int i = 0; i < n; i++) {
		c1[i + 1] = c1[i] + (s[i] == 'A'); 
	}
	for (int i = 0; i < m; i++) {
		c2[i + 1] = c2[i] + (t[i] == 'A'); 
	}
	int q;
	cin >> q;
	while(q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int val1 = (c1[b] - c1[a - 1]) + (b - a + 1 - (c1[b] - c1[a - 1])) * 2;
		int val2 = (c2[d] - c2[c - 1]) + (d - c + 1 - (c2[d] - c2[c - 1])) * 2;
		cout << (val1 % 3 == val2 % 3 ? "YES\n" : "NO\n");
	}
}
