#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

  vector<int> cnt(100100);
  for(int i = 0; i < 100100; i++){
    cnt[i] = 0;
  }
  int N;
  cin >> N;
  int A;
  for(int i = 0; i < N; i++){
    cin >> A;
    A--;
    cnt[A]++;
  }

  int ans = 0;
  vector<int> vec;
  for(int i = 0; i < 100100; i++){
    if(cnt[i] >= 1){
      ans++;
    }
    if(cnt[i] >= 2){
      vec.push_back(cnt[i]);
    }
  }

  if(vec.size() >= 1){
    sort(vec.begin(), vec.end());

    for(int i = 0; i + 1 < vec.size(); i++){
      vec[i+1] -= (vec[i] - 1);
    }

    ll last = vec[vec.size()-1];

    if(last % 2 == 0){
      ans--;
    }
  }

  cout << ans << endl;

  return 0;
}
