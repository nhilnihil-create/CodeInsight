#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  ll x;
  cin >> x;
  vector<ll> A(1000000);
  A[0] = 0;
  ll i = 1;
  while(1){
    A[i] = A[i-1] + i;
    if(A[i] >= x){
      break;
    }
    ++i;
  }
  cout << i << endl;
  return 0;
}
