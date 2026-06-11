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

int N, T;
int A[100010];

void solve() {
	cin >> N >> T;

	int cnt = 0, cost = 0;
	int small = 1000000010;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i == 0) continue;
		
		small = min(small, A[i-1]);

		int gap = A[i] - small;
		
		if (cost == gap) 
			cnt++;
		
		else if (cost < gap) {
			cnt = 1;
			cost = gap;
		}
	}

	int ans = cnt;
	if (!ans) ans++;

	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}