
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;

int n;
int a[100010], b[100010];
vector<vector<int>> edge;
int d1[100010], dn[100010];

void dfs(int d[], int node) {
	for (auto itr = edge[node].begin(); itr < edge[node].end(); itr++) {
		if (d[*itr] != INF)continue;
		d[*itr] = d[node] + 1;
		dfs(d, *itr);
	}
	return;
}


int main() {
	int i; 
	cin >> n;
	edge.resize(n);
	for (i = 0; i < 100010; i++) {
		d1[i] = INF; dn[i] = INF;
	}

	for (i = 0; i < n-1; i++) {
		int pa, pb; cin >> pa >> pb;
		pa--; pb--;
		a[i] = pa; b[i] = pb;
	}

	for (i = 0; i < n - 1; i++) {
		edge[a[i]].push_back(b[i]);
		edge[b[i]].push_back(a[i]);
	}

	d1[0] = 0; dn[n - 1] = 0;
	dfs(d1, 0);
	dfs(dn, n-1);

	int f = 0, s = 0;
	for (int i = 0; i < n; i++) {
		if (d1[i] <= dn[i]) {
			f++;
		}
		else s++;
	}

	cout << ((f > s) ? "Fennec" : "Snuke") << endl;

	return 0;
}