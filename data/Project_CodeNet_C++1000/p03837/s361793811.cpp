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
static const int MAX = 100001;
static const ll MOD = 1000000007;
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

int d[1001][1001]; // d[u][v]は辺e=(u, v)のコスト（存在しない場合はINF、ただし[i][i]=0とする）
int V, N, M;
vector<pair<pair<int, int>, int> > v;

void warshall_floyd(){
	cin >> N >> M;
	V = N;
    rep(i, V){
        rep(j, V){
            d[i][j] = INTINF;
        }
    }


	rep(i, M){
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		d[a][b] = c;
		d[b][a] = c;
		v.push_back({{a, b}, c});
	}

    rep(i, V) d[i][i] = 0;
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

	int cnt = 0;
	rep(k, M){
		auto e = v[k].first;
		int c = v[k].second;
		// print(e.first, e.second);
		bool ok = true;
		rep(i, N){
			rep2(j, i + 1, N){
				// print(i, j, d[i][j], c, d[i][e.first] + d[e.first][e.second] + d[e.second][j], d[i][e.second] + d[e.first][e.second] + d[e.first][j]);
				if(d[i][j] == d[i][e.first] + c + d[e.second][j] || d[i][j] == d[i][e.second] + c + d[e.first][j]){
					ok = false;
				}
			}
		}
		if(ok) {
			cnt++;
		}
	}

	cout << cnt << endl;
}


int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	warshall_floyd();

	return 0;
}
