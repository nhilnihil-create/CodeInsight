#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
using lint = long long;
using uint = unsigned int;
using ulint = unsigned long long;
using ldouble = long double;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
using v1i = vector<int>;
using v1li = vector<lint>;
using v2i = vector<vector<int>>;
using v2li = vector<vector<lint>>;
using v3i = vector<vector<vector<int>>>;
using v3li = vector<vector<vector<lint>>>;
using v1b = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<vector<vector<bool>>>;
using v1c = vector<char>;
using v2c = vector<vector<char>>;
using v3c = vector<vector<vector<char>>>;
constexpr lint mod1 = 1e9+7;
constexpr lint mod2 = 998244353;

int main() {
  lint n, p = 0, q = 0, r = 0, s = 0;
  cin >> n;
  v1i v(n), w(n), a(n), b(n);
  rep(i, n) cin >> v[i];
  w[0] = v[0];
  rep(i, n-1) w[i+1] = w[i] + v[i+1];
  rep(i, n){
    a[i] = w[i];
    a[i] += r;
    if(i % 2 == 0){
      if(a[i] < 0){
        p += 1-a[i];
        r += 1-a[i];
      }
      else if(a[i] == 0){
        p += 1;
        r += 1;
      }
    }
    else{
      if(a[i] > 0){
        p += a[i]+1;
        r -= a[i]+1;
      }
      else if(a[i] == 0){
        p += 1;
        r -= 1;
      }
    }
  }
  rep(i, n){
    b[i] = w[i];
    b[i] += s;
    if(i % 2 == 1){
      if(b[i] < 0){
        q += 1-b[i];
        s += 1-b[i];
      }
      else if(b[i] == 0){
        q += 1;
        s += 1;
      }
    }
    else{
      if(b[i] > 0){
        q += b[i]+1;
        s -= b[i]+1;
      }
      else if(b[i] == 0){
        q += 1;
        s -= 1;
      }
    }
  }
  cout << min(p, q) << endl;
  return 0;
}