#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	string ans = "NO";
	if (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0])ans = "YES";
	cout << ans << endl;
	return 0;
}
