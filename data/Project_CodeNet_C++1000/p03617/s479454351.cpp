#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll Q,H,S,D,N;cin>>Q>>H>>S>>D>>N;
  if(N%2==0) cout << min(min(8*Q,4*H),min(2*S,D))*N/2 << endl;
  else cout << min(min(8*Q,4*H),min(2*S,D))*(N/2) + min(4*Q,min(2*H,S)) << endl;
}