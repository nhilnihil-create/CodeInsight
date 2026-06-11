#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_a() {
	ll n, m;
	ll x, y;
	ll a, b;
	ll k;
	//string s, t;
	ll l_ans = 0;
	string s_ans = "NG";

	cin >> a >> b;

	if (a == 1 && b == 1) {
		s_ans = "Draw";
	}
	else if (a == 1) {
		s_ans = "Alice";
	}
	else if (b == 1){
		s_ans = "Bob";
	}
	else {
		if (a < b) {
			s_ans = "Bob";
		}
		else if (a > b) {
			s_ans = "Alice";
		}
		else {
			s_ans = "Draw";
		}
	}

	cout << s_ans << "\n";

	return;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_a();

	return 0;
}