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
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_b() {
	ll n, m;
	ll x, y;
	//ll a, b, c;
	//ll k;
	string s;
	ll l_ans = 0;
	float f_ans = 0;
	string s_ans;

	string sa, sb, sc;
	cin >> sa >> sb >> sc;

	s_ans = "a";
	while (1) {
		if (s_ans == "a") {
			if (sa.size() == 0) {
				s_ans = "A";
				break;
			}
			s_ans = sa[0];
			sa = sa.substr(1, sa.size() - 1);
		}
		else if (s_ans == "b") {
			if (sb.size() == 0) {
				s_ans = "B";
				break;
			}
			s_ans = sb[0];
			sb = sb.substr(1, sb.size() - 1);
		}
		else {
			if (sc.size() == 0) {
				s_ans = "C";
				break;
			}
			s_ans = sc[0];
			sc = sc.substr(1, sc.size() - 1);
		}
	}

	cout << s_ans << "\n";

}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_b();

	return 0;
}
