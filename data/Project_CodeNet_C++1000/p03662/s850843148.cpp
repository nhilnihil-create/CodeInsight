#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>	// upper_bound(A, A+N, num), lower_bound(A, A+N, num)
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <vector>		// V[i],  push_back(x), pop_back(), insert(index, x), erase(index), sort(v.begin(), v.end(), greater<int>())
#include <list>			// push_front(x), push_back(x), pop_front(), pop_back(), insert(index, x)
#include <queue>		// push(x), front(), pop()
#include <deque>
#include <stack>		// push(x), top(), pop()
#include <map>			// M[key],  insert(key, val), erase(key), find(key), 
#include <set>			// insert(key), erase(key), find(key)

using namespace std;
typedef long long ll;
// typedef pair<int, int> P;

#define PI 3.141592653589793)
#define MOD 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)

int N;
vector<int> ve[100001];
bool flag[100001];
int d[2][100001];

void dfs(int pos, int num, int start) {
	for (int i = 0; i < ve[pos].size(); i++) {
		d[start][pos] = num;
		if (!flag[ve[pos][i]]) {
			flag[pos] = true;
			dfs(ve[pos][i], num + 1, start);
			flag[pos] = false;
		}
	}
}

void solve() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	dfs(1, 0, 1);
	dfs(N, 0, 0);

	int fe = 0, su = 0;
	for (int i = 1; i <= N; i++) {
		if (d[1][i] <= d[0][i]) fe++;
		else su++;
	}
	cout << (fe > su ?  "Fennec" : "Snuke" )<< endl;
	
}

int main() {
	solve();
	return 0;
}