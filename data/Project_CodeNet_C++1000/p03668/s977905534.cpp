#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 37;

int gn[maxn];
vector <int> t[maxn];

void dfs (int v, int p = -1) { // find grundy_number
	for (auto w : t[v]) {
		if (w != p) {
			dfs (w, v);
			gn[v] ^= gn[w];
		}
	}
	gn[v] ++;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].PB (u);
		t[u].PB (v);
	}
	dfs (1);
	if (gn[1] == 1)
		cout << "Bob" << endl;
	else
		cout << "Alice" << endl;
}
