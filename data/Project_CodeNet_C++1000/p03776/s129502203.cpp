#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define memr(dp, val) memset(dp, val, sizeof(dp))
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define print(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define print(...)
#endif

long long combi(long long n, long long r) {
    if(r > n) return 0;
    if (r == 0) {
        return 1;
    }

    return (n - r + 1) * combi(n, r - 1) / r;
}
int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	int N, A, B; cin >> N >> A >> B;
	vector<ll> v(N);
	map<ll, ll> mp;
	rep(i, N) {
		cin >> v[i];
		mp[v[i]]++;
	}
	sort(ALL(v), greater<ll>());
	double ma = 0;
	ll ma_idx = 0;
	double sum = 0;
	rep(i, A){
		sum += v[i];
	}
	rep(i, B+1){
		if(ma < v[i] / (A + i)){
			ma = v[i] / (A + i);
			ma_idx = A + i;
		}
		if(i == B) break;
		sum += v[i];
	}
	bool isSame = false;
	vector<ll> res;
	rep(i, ma_idx){
		res.push_back(v[i]);
	}
	if(res[0] == res[res.size()-1]) isSame = true;
	if(isSame){
		ll ans = 0;
		rep2(i, A, B+1){
			if(i <= mp[res[0]]){
				ans += combi(mp[res[0]], i);
			}
		}
		cout << res[0] << endl;
		cout << ans << endl;
	}
	else
	{
		ll tmp = 0;
		rep(i, res.size()){
			if(res[res.size()-1] == res[i]) tmp++;
		}
		double calc = accumulate(ALL(res), 0.0) / res.size();
		cout <<calc << endl;
		cout << combi(mp[res[res.size()-1]], tmp) << endl;
	}

	return 0;
}
