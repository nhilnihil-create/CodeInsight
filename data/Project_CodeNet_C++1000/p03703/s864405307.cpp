#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
using P = pair<ll,ll>;

template <typename T>
class BIT {
  int n;
  vector<T> bit;
public:
  BIT(int _n) {
    n = _n;
    bit = vector<T>(n+1,(T)0);
  }
  T sum(int i) {
    T s = 0;
    while(i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
  }
  void add(int i, T x) {
    while(i <= n){
    bit[i] += x;
    i += i & -i;
    }
  }
};

int main(){
  int n; ll k, a;
  cin >> n >> k;
  ll sum[n+1];
  sum[0] = 0;  
  vector<P> s(n+1);
  rep(i,n) {
    cin >> a;
    sum[i+1] = sum[i] + a; 
  }
  rep(i,n+1) s[i] = P(sum[i]-k*i,i); 
  sort(s.begin(),s.end());
  vector<int> v(n+1);
  rep(i,n+1) v[s[i].second] = i+1;
  BIT<ll> bit(n+1);
  ll ans = 0;
  rep(i,n+1) {
    ans += bit.sum(v[i]);
    bit.add(v[i],1);
  }
  cout << ans << endl;
  return 0;
}