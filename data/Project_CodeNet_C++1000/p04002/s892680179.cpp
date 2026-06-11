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
typedef pair<int, int> P;

#define PI 3.141592653589793)
#define MOD 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)

map<pair<int, int>, int> xy;
int H, W, N;
ll ans[10];

void solve() {
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> b >> a;
		for (int y = max(2, b-1); y <= min(H-1, b+1); y++) {
			for (int x = max(2, a - 1); x <= min(W-1, a + 1); x++) {
				xy[P(x, y)]++;
			}
		}
	}

	ll sum = 0;
	for (auto itr = xy.begin(); itr != xy.end(); ++itr) {
		ans[itr->second]++;
		sum++;
	}
	ans[0] = ((ll)H - 2)*(W - 2) - sum;
	
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	solve();
	return 0;
}