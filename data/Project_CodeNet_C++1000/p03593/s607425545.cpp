#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
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

void out(bool yes){
  if(yes){
    cout << "Yes" << endl;
  }
  else{ 
    cout << "No" << endl;
  }
}

int main(int argc, const char * argv[]) {
  std::cout << std::fixed << std::setprecision(15);

  int H, W; cin >> H >> W;
  if(H == 1 && W == 1){
    out(true);
    return 0;
  }
  
  int one = 0;
  int two = 0;
  if(H % 2 == 1 && W % 2 == 1){
    one = 1;
    two = H / 2 + W / 2;
  }
  else if(H % 2 == 1){
    two = W / 2 ;
  }
  else if(W % 2 == 1){
    two = H / 2 ;
  }
  int four = (H / 2) * (W / 2);
  DEBUG(four);
  DEBUG(two);
  DEBUG(one);

  vector<int> v(30);
  rep(i, H){
    string str;
    cin >> str;
    rep(j, str.size()){
      v[str[j] - 'a']++;
      if(v[str[j] - 'a'] >= 4 && four > 0){
        four--;
        v[str[j] - 'a'] -=4;
      }
    }
  }

  rep(j, 1000)
  rep(i, 30){
    if(v[i] >= 2 && two > 0){
      two--;
      v[i] -= 2;
    }
  }

  rep(i, 30){
    if(v[i] >= 1 && one > 0){
      one--;
      v[i]--;
    }
  }

  rep(i, 30){
    DEBUG(v[i]);
  }

  DEBUG(four);
  DEBUG(two);
  DEBUG(one);
  if(!four && !two && !one){
    out(true);
  }
  else{
    out(false);
  }
}  
