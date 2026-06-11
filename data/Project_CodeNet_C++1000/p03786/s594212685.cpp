#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N),R(N);
  for(int i(0);i<N;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  ll l = 0,r = N;
  while(l+1<r){
    ll x = (l+r)/2;
    bool ok = [&]{
      ll now = A[x];
      for(int i(N-1);i>=0;i--){
        if(i==x) continue;
        if(now*2 < A[i]) return false;
        now += A[i];
      }
      return true;
    }();
    if (ok) l = x;
    else r = x;
  }
  cout << l+1 << endl;
  return 0;
}
