#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>

#define int long long
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int nextInt() {int a; cin >> a; return a;}
char nextChar() {char a; cin >> a; return a;}
double nextDouble() {double a; cin >> a; return a;}
string nextString() {string a; cin >> a; return a;}

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

int rk[100010];

signed main() {
	int n;
	cin >> n;

	vector<int> x;
	inputVector(x, n);

	int ret = 1;
	int num = 0;
	int pt = 0;
	int pti = 0;

	rep(i, n) {
		num++;
		ret *= num;
		ret %= MOD;
		//cerr << "i:" << i << endl;
		//cerr << " num:" << num << endl;
		//cerr << " ret:" << ret << endl;
		if (x[i] % 2 == 0 && (x[i] + 1 - pt) / 2 < (i + 1 - pti)) {
			num--;
			pt = x[i];
			pti = i + 1;
		}
	}

	cout << ret << endl;

    return 0;
}
