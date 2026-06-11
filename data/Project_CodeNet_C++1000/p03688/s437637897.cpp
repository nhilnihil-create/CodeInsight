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

  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  int max_val = a[0];
  int min_val = a[0];

  for(int i = 0; i < N; i++){
    chmax(max_val, a[i]);
    chmin(min_val, a[i]);
  }

  if(max_val - min_val > 1){
    cout << "No" << endl;
  }else if(min_val == N-1){
    cout << "Yes" << endl;
  }
  else{

    int cnt_max = 0;
    int cnt_min = 0;
    for(int i = 0; i < N; i++){
      if(a[i] == max_val){
        cnt_max++;
      }else{
        cnt_min++;
      }
    }

    // 残り N - cnt_minで、max_val分割できるか判定

    if((max_val - cnt_min) == 0){
      cout <<"No" << endl;
    }else if((N-cnt_min)/(max_val-cnt_min) >= 2){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }


  return 0;
}
