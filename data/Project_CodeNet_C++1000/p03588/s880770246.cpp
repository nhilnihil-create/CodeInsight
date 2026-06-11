#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<ll, ll> p[100005];

int main() {
	int n; cin >> n;
	rep(i, 0, n) cin >> p[i].first >> p[i].second;
	sort(p, p + n);
	cout << p[n - 1].first + p[n - 1].second << endl;
}
