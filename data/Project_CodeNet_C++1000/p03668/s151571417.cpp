#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, x, y;
vector<int>v[100000];
bool vis[100000];

int dfs(int x) {
	vis[x] = true;
	int t = 0;
	for (int i : v[x]) {
		if (!vis[i]) {
			t ^= dfs(i);
		}
	}
	return t + 1;
}

int main() {
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> x >> y;
		--x;
		--y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (dfs(0) == 1) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}