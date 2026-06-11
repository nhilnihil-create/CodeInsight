#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  int N; cin >> N;
  vector<int> a(N); rep(i, N) cin >> a.at(i);
  bool odd = (N%2==1);
  vector<int> ans(N);
  if(odd){
    rep(i, N){
      if(i%2==1){
        ans.at(N/2+i/2+1) = a.at(i);
      } else {
        ans.at(N/2-i/2) = a.at(i);
      }
    }
  } else {
    rep(i, N){
      if(i%2==1){
        ans.at(N/2-i/2-1) = a.at(i);
      } else {
        ans.at(N/2+i/2) = a.at(i);
      }
    }
  }
  cout << ans.at(0);
  rep(i, N-1) cout << " " << ans.at(i+1);
  cout << endl;
  return 0;
}
