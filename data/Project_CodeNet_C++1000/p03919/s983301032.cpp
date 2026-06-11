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

#define PI 3.141592653589793
#define MOD 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)

string s[27][27];

void solve() {
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> s[i][j];

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (s[i][j] == "snuke") {
				char a = 'A' + j; int n = 1 + i;
				cout << a << n << endl;
			}
}

int main() {
	solve();
	return 0;
}