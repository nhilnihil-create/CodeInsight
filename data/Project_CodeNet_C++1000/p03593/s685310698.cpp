#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;

  vector<int> cnt(26);

  rep(i, 26) cnt[i] = 0;

  rep(i, H){
    string s;
    cin >> s;
    rep(j, W){
      cnt[s[j]-'a']++;
    }
  }

  int cnt_4 = 0;
  int cnt_2 = 0;

  rep(i, 26){

    cnt_4 += cnt[i] / 4;
    cnt_2 += cnt[i] / 2;

  }

  int req_4 = (H/2) * (W/2);
  int req_2 = 2 * req_4 + (H/2) * (W%2) + (H%2) * (W/2);

  if(cnt_4 >= req_4 && cnt_2 >= req_2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }


  return 0;
}
