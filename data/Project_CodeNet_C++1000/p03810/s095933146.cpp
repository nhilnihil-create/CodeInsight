/*input
5
3 5 7
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <cstdlib>
#include <list>
#include <cassert>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define N 100005
// const int INF = 1e18;

int n;
int a[N];
int odd, even;
bool all1 = true;

void done(int x, int y) {
	int t = (x + y) % 2;
	if (t == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	exit(0);
}

void prep() {
	odd = 0; even = 0; all1 = true;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 1) all1 = false;
		if (a[i] % 2 == 0) even++;
		else odd++;
	}
}

void process(int x) {
	odd = 0; even = 0; all1 = true;
	int gcd = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if ((n - 1) % 2 == 1) done(1, x);
			else done(2, x);
		}
		else if (a[i] % 2 == 1) a[i]--;
		if (gcd == -1) gcd = a[i];
		else gcd = __gcd(a[i], gcd);
	}
	for (int i = 1; i <= n; i++) {
		a[i] /= gcd; if (a[i] > 1) all1 = false;
		if (a[i] % 2 == 0) even++;
		else odd++;
	}
}

void check(int x) {
	if (all1) done(2, x);
	if (even == 0) done(1, x);
	if (even % 2) done(1, x);
	if (odd >= 2) done(2, x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	prep();
	int turn = 1;
	while (1) {
		turn++;
		check(turn);
		process(turn);
	}
}