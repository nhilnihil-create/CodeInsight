// In The Name Of God
#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
#include <climits>
#include <map>
#include <queue>
#include <math.h>
#include <iomanip>

#define sqr(A) ((A) * (A))
#define F first
#define S second
#define MP make_pair
#define BSZ  __builtin_popcount
#define ALL(A) A.begin(), A.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; ; i++)
		if (i * (i + 1) / 2 >= n)
			return cout << i << endl, 0;
}
