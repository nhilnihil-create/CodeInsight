#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
 
#define ll long long
#define pb push_back
#define vi vector<int>
#define sz(a) (int((a).size()))
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
 
using namespace std;
 
const int mod = 998244353;
const int inf = (int)2e9;
const ll INF = (ll)2e18;
const int N = 100100;

string s;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	for (int i = 1; i < sz(s); i++) {
		if (s[i] == s[i - 1]) {
			cout << i << " " << i + 1 << endl;
			return 0;
		}
		if (i > 1 && s[i] == s[i - 2]) {
			cout << i - 1 << " " << i + 1 << endl;
			return 0;
		}
	}
	cout << "-1 -1\n";

	return 0;
}