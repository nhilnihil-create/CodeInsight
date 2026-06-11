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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, L, T;
    cin >> N >> L >> T;
    // debug(N, L, T);

    VI X, W;
    rep(i, N){
      ll x, w;
      cin >> x >> w;
      X.push_back(x);
      W.push_back(w);
    }

    // T秒後
    VI temp(N);
    rep(i, N){
      if(W[i]==1){
        temp[i] = (X[i] + T) % L;
      }else{
        temp[i] = (X[i] - T) % L;
        if(temp[i]<0){
          temp[i] += L;
        }
      }
    }
    ll temp0 = temp[0];
    sort(ALL(temp));
    
    ll x = X[0];
    ll w = W[0];
    ll hit = 0;
    FOR(i, 1, N){
      if(W[i]==w) continue;
      float interval = L/2.0;
      // 右向き
      if(w==1){
        double t;
        if(x<X[i]){
          t = (X[i]-x)/2.0;
        }else{
          t = (L - (x-X[i]))/2.0;
        }
        if(t>T) continue;
        hit++;
        double rest_T = T-t;
        hit += rest_T / interval;
        // hit += 2*rest_T / L;
      }
      // 左向き
      else{
        double t;
        if(x<X[i]){
          double dist = L - (X[i]-x);
          t = dist/2;
        }else{
          t = (x-X[i])/2.0;
        }
        if(t>T) continue;
        hit++;
        double rest_T = T-t;
        hit += rest_T / interval;
        // hit += 2*rest_T/L;
      }
      // hit %= N;
    }
    debug(hit);

    ll cnt = 0;
    for(ll t : temp){
      if(t==temp0) cnt++;
    }    
    if(cnt==2){
      hit--;
      // if(w==2){
      //   hit--;
      // }else{
      //   hit++;
      // }
    }



    VI Ans(N);
    // 右向き
    if(w==1){
      hit %= N;
    }
    else{
      hit %= N;
      hit = -hit;
      if(hit<0) hit+=N;
    }


    // cout << temp0 << " ni " << hit << " ga i ru" << endl;
    Ans[hit] = temp0;
    VI::iterator it;
    
    // it = lower_bound(ALL(temp), temp0);
    if(w==1){
      it = lower_bound(ALL(temp), temp0);
      it++;
    }else{
      it = upper_bound(ALL(temp), temp0);
      // it--;
    }
    FOR(i, 1, N){
      if(it==temp.end()) it = temp.begin();
      Ans[(hit+i)%N] = *it;
      it++;
    }


    for(ll a : Ans){
      p(a);
    }
    
    return 0;
}