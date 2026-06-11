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

  int N, x;
  cin >> N >> x;
  int M = 2 * N -1;
  if(x == 1 || x == M){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
    x--;

    vector<int> used(M);
    vector<int> ans(M);

    int now = 0;
    if(x != 1){
      used[x-2] = 1;
      used[x+1] = 1;
      used[x] = 1;
      used[x-1] = 1;
      for(int i = 0; i < M; i++){
        if(i == N-2){
          ans[i] = x-2;
          
        }else if(i == N-1){
          ans[i] = x+1;
          
        }else if(i == N){
          ans[i] = x;
          
        }else if(i == N+1){
          ans[i] = x-1;
          
        }else{
          while(used[now] == 1){
            now++;
          }
          ans[i] = now;
          used[now] = 1;
        }
      }
    }else{
      used[x+1] = 1;
      used[x] = 1;
      used[x-1] = 1;
      if(x+2 < M){
        used[x+2] = 1;
      }
      for(int i = 0; i < M; i++){
        if(i == N-2){
          ans[i] = x+1;
          
        }else if(i == N-1){
          ans[i] = x;
          
        }else if(i == N){
          ans[i] = x-1;
          
        }else if(i == N+1){
          ans[i] = x+2;
          
        }else{
          while(used[now] == 1){
            now++;
          }
          ans[i] = now;
          used[now] = 1;
        }
      }
    }

    for(int i = 0; i < M; i++){
      cout << ans[i] +1 << endl;
    }


  }


  return 0;
}
