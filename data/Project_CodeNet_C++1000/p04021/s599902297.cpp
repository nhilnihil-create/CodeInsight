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
  vector<ll> A(N), B(N);
  ll tmp;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    B[i] = A[i];
  }

  set<ll> Odd, Even;
  sort(B.begin(), B.end());
  for(int i = 0; i < N; i++){
    if(i%2 == 0){
      Even.insert(B[i]);
    }else{
      Odd.insert(B[i]);
    }
  } 

  int cnt = 0;
  for(int i = 0; i < N; i++){
    if(i%2 == 0){
      if(Even.find(A[i]) == Even.end()){
        cnt++;
      }
    }else{
      if(Odd.find(A[i]) == Odd.end()){
        cnt++;
      }
    }
  }

  cout << cnt / 2 << endl;
  
  return 0;
}
