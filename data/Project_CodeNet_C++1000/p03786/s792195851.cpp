#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<ll> A(N), AA(N, 0);
  REP(i, N){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  REP(i, N){
    if(i == 0 || i == N-1){
      AA[i] = A[i];
    }else{
      AA[i] = AA[i-1]+A[i];
    }
  }
  ll ans = 1;
  for(int i = N-1; i > 0; i--){
    if(A[i] <= AA[i-1]*2){
      ans++;
    }else{
      break;
    }
  }
  cout << ans << endl;
}
