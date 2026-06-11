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
template<class T> inline bool int_ceil(T a, T b) { T res = a / b; if(a % b != 0) res++; return res; }
template<typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
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

vector<pair<char, int> > Ranlength(string str){
    vector<pair<char, int> > ranlength;

    pair<char, int> f;
    char lastChar;
    int cnt = 0;
    rep(i, str.size()){
        if(lastChar != str[i] || i == str.size()){
            if(i!=0){
                f = make_pair(lastChar, cnt);
                ranlength.push_back(f);
            }
            lastChar = str[i];
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    f = make_pair(lastChar, cnt);
    ranlength.push_back(f);

    // rep(i, ranlength.size()){ // for debug
    //     cout << ranlength[i].first << ranlength[i].second << endl;
    // }
    return ranlength;
}

ll sdp[MAX+1], tdp[MAX+1];


int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	string s, t; cin >> s >> t;
	memr(sdp, 0);
	memr(tdp, 0);
	int q; cin >> q;

	rep(i, s.size()){
		sdp[i+1] = sdp[i] + (s[i] == 'A'? 1 : 2);
	}
	rep(i, t.size()){
		tdp[i+1] = tdp[i] + (t[i] == 'A'? 1 : 2);
	}

	rep(i, q){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll tmp = sdp[b] - sdp[a - 1];
		tmp %= 3;
		ll tmp2 = tdp[d] - tdp[c - 1];
		tmp2 %= 3;
		if(tmp == tmp2){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}
