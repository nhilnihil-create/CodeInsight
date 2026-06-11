#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>
#include<utility>
#include<numeric>

#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
#define dwn(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define V vector<int>
#define VV vector<V>
#define VVV vector<VV>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;
const ll inf = (ll)1e18;
const ll MOD{ (ll)1e9 + 7 };
const long double EPS = 1e-10;

int main() {
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		if (i * (i + 1) / 2 >= n) {
			for (ll j = i; j >= 1; j--) {
				if (n - j >= 0) {
					n -= j;
					cout << j << endl;
				}
			}
			return 0;
		}
	}
}