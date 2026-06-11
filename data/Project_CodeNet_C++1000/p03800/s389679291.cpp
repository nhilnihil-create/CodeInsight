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
 * os xw
 */
int n;
string s;
void func(vector<char> ans) {
	map <char, char> c;
	c['S'] = 'W';
	c['W'] = 'S';
	for (int i = 1; i < n - 2; i++) {
		if (s[i] == 'o') {
			ans[i + 1] = (ans[i] == 'S' ? ans[i - 1] : c[ans[i - 1]]);
		}
		else {
			ans[i + 1] = (ans[i] == 'W' ? ans[i - 1] : c[ans[i - 1]]);
		}
	}
	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (ans[i] == 'S') {
			if (s[i] == 'o') {
				ok &= (ans[i - 1] == ans[(i + 1) % n]);
			}
			else {
				ok &= (ans[i - 1] != ans[(i + 1) % n]);
			}
		}
		else {
			if (s[i] == 'x') {
				ok &= (ans[i - 1] == ans[(i + 1) % n]);
			}
			else {
				ok &= (ans[i - 1] != ans[(i + 1) % n]);
			}
		} 
	}
	if(!ok)
		return;
	for (auto g : ans)
		cout << g;
	exit(0);
}
int main() {
	cin >> n;
	cin >> s;
	// first fix S in the start
	vector <char> ans(n);
	ans[0] = 'S';
	if (s[0] == 'o') {
		ans[n - 1] = 'S';
		ans[1] = 'S';
		func(ans);
		ans[n - 1] = 'W';
		ans[1] = 'W';
		func(ans);
	}
	else {
		ans[n - 1] = 'S';
		ans[1] = 'W';
		func(ans);
		ans[n - 1] = 'W';
		ans[1] = 'S';
		func(ans);
	}
	ans[0] = 'W';
	if (s[0] == 'o') {
		ans[n - 1] = 'S';
		ans[1] = 'W';
		func(ans);
		ans[n - 1] = 'W';
		ans[1] = 'S';
		func(ans);
	}
	else {
		ans[n - 1] = 'S';
		ans[1] = 'S';
		func(ans);
		ans[n - 1] = 'W';
		ans[1] = 'W';
		func(ans);
	}
	cout << -1;
}
