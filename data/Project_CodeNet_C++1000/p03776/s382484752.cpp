#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;

// tourist set
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// tourist set end

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<'\n'
#define p2(s, t) cout << (s) << " " << (t) << '\n'
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << '\n'
#define p_yes() p("YES")
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

const int N_MAX = 55;
ll pascal[N_MAX][N_MAX] = {};

void calc_pascal(){
    FOR(i, 0, N_MAX){
        pascal[i][0] = 1;
    }
    pascal[1][1] = 1;

    FOR(i, 2, N_MAX){
        for(int j=1; j<=i; j++){
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }
}

ll nCr(ll n, ll r){
    return pascal[n][r];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, A, B;
    cin >> N >> A >> B;

    calc_pascal();

    VI V(N);
    rep(i, N){
        cin >> V.at(i);
    }
    sort(ALL(V), greater<ll>());

    double sum = 0;
    rep(i, A){
      sum += V[i];
    }
    cout << setprecision(20);
    p(sum/A);

    debug(V);
    
    // A個のみ考える
    ll mi = V[A-1];

    // 全体でmiはいくつあるか
    ll mi_all = 0;
    rep(i, N){
      if(V[i]==mi) mi_all++;
    }

    if(V[0]!=V[A-1]){
      // A個までにいくつ必要か
      ll cnt = 0;
      rep(i, A){
        if(V[i]==mi) cnt++;
      }

      ll ans = nCr(mi_all, cnt);
      p(ans);
      return 0;
    }

    // 以降、A個まで見て先端と後端が同じ場合
    // この場合は伸ばせる
    ll ans = 0;
    FOR(i, A-1, B){
      if(V[i]==mi){
        ll n = i+1;
        ans += nCr(mi_all, n);
      }else{
        break;
      }
    }    
    p(ans);
    
    return 0;
}