#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-9;
//---------------------------------//

/*--------DEBUG-------------*/
ll debugans;
string to_str(ll x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

bool queryk(ll n) {
	ll ans = debugans;
	
	bool res = false;
	if (n <= ans && to_str(n) <= to_str(ans)) res = true;
	if (n > ans && to_str(n) > to_str(ans)) res = true;
	
	puts(res ? "Y" : "N");
	return res;
}
/*---------------------*/

ll to_ll(string str) {
	stringstream ss(str);
	ll res;
	ss >> res;
	
	return res;
}


ll powe(ll x, ll n) {
	ll res = 1;
	REP(i, n) res *= x;
	return res;
	/*
	if (n == 0) return 1;
	ll res = powe(x * x, n / 2);
	if (n & 1) res = res * x;
	*/
	return res;
}

bool query(ll n) {
	cout << "? " << n << endl;

//return queryk(n); // --DEBUG--

	string ans; cin >> ans;
	
	return ans == "Y"; 
}

int askfl() {
	int one = -1;
	bool bef;
	
	REP(i, 10) {
		bool now = query(powe(10, i));
		if (i != 0 && bef != now) one = i;
		bef = now;
	}
	
	int nine = -1;
	FOR(i, 1, 11) {
		bool now = query(powe(10, i) - 1);
		if (i != 1 && bef != now) nine = i;
		bef = now;
	}
	
	int keta;
	
	ll l, r;
	if (one != -1) keta = one;
	else keta = nine;
	
	return keta;
}

int askdg(string num, int k) {
	int l = 0, r = 11;
	bool bef = false;
	
	while (r - l > 1) {
		int m = (r + l) / 2;
		if (m == 10) { l = m; continue; }
		
		num[k] = m + '0';
		bool now = query(to_ll(num.c_str()));
		
		if (now) r = m;
		else l = m;
		
		bef = now;
	}
	
	return l;
}

int main() {
	//cin >> debugans; // --DEBUG--
	
	int keta = askfl();
	
	string ans = "";
	REP(i, keta + 1) ans += "0";
	
	REP(i, keta + 1) {
		int num = askdg(ans, i);
		
		if (num == 0) {
			if (i == 0) ans[i] = '1';
			else ans[i] = '0';
		}
		else if (num == 10) {
			if (i == keta) {
				int p = keta - 1;
				while (p >= 0 && ans[p] == '9') p--;
				if (p >= 0) {
					ans[p]++;
					FOR(j, p + 1, keta + 1) ans[j] = '0';
				}
			}
			else ans[i] = '9';
		}
		else ans[i] = num + '0';
	}
	
	ans = ans.substr(0, (int)ans.size() - 1);
	
	ll N;
	if (ans.size() == 0) N = 1;
	else N = to_ll(ans);
	
	cout << "! " << N << endl;
	return 0;
}
