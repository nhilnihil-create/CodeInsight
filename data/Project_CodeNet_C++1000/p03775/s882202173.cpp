#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


int main() {
    ll n;
    cin >> n;
    vector<ll> res=divisor(n), num(2, 1);
    ll l = sqrt(n);
    ll n_min = 0;
    for (auto x: res){
        if (x <= l) n_min = max(n_min, x);
    }
    num[0] = n_min;
    num[1] = n / n_min;
    ll count = 0;
    while (num[1]>0){
        num[1] /= 10;
        count++;
    }
    cout << count << endl;
    //printf("%.12f", ans);
}