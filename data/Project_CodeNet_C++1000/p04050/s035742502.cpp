#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define pb push_back
#define point pair <int, int>
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXN = 2e3 + 1;

int n, k;
vector <int> a, c;

int main() {
	ios::sync_with_stdio(false);
	srand(time(0));
	//read(FILENAME); 
	cin >> n >> k;
	if (k == 1) {
		int b;
		cin >> b;
		cout << b << endl;
		if (b == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
			cout << b - 1 << ' ' << 1 << endl;
		}
		return 0;
	}
	for (int i = k; i--;) {
		int b;
		cin >> b;
		if (b & 1) c.pb(b);
		else a.pb(b);
	}
	if (c.size() > 2) {
		cout << "Impossible" << endl; 
	} else {
		if (c.size() >= 1) a.insert(a.begin(), c[0]);
		if (c.size() >= 2) a.pb(c[1]);
		for (int i = 0; i < k; ++i) cout << a[i] << ' ';
		cout << endl;
		cout << k - int(a[0] == 1) << endl;
		for (int i = 0; i < k; ++i) {
			if (a[i] - int(i == 0) + int(i + 1 == k))
				cout << a[i] - int(i == 0) + int(i + 1 == k) << ' ';
		}
		cout << endl;
	}
	
}