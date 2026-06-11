#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
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
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

int main(int argc, const char * argv[]) {
  std::cout << std::fixed << std::setprecision(15);

  int N, M; cin >> N >> M;
  if(!(1 < M && M < 2 * N - 1)){
    cout << "No" << endl;
    return 0;
  }
  vector<int> v;
  rep2(i, M-1, M+2){
    v.push_back(i);
  }
  int tmp = v[2];
  v[2] = v[0];
  v[2] = tmp;

  int k = 0;
  rep2(i, 1, 2 * N) {
    if(M-1 <= i && i <= M+1) continue;
    if(k < (2 * N - 1 - 3) / 2){
      k++;
      v.insert(v.begin(), i);
    }
    else{
      k++;
      v.push_back(i);
    }
  }

  cout << "Yes" << endl;

  rep(i, v.size()){
    if(i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}