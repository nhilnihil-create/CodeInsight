#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=0;i--)
#define rep_re(i,s,n)for(int i = n;i>=0;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_M = 100001;

ll N[200001] = {};
int main() {
	ll n, x; cin >> n >> x;

	if (x == 1 || x == 2 * n - 1) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	N[n - 2] = x - 1;
	N[n - 1] = x;
	N[n] = x + 1;
	ll pos = 0;

	for (int i = 1; i <= 2 * n - 1;) {
		if (i == x || i == x - 1 || i == x + 1) {
			i++; continue;
		}
		if (N[pos] != 0) {
			pos++;
			continue;
		}
		N[pos] = i;
		pos++;
		i++;
	}

	rep(i, 0, 2 * n - 1) {
		cout << N[i] << endl;
	}
	return 0;
}