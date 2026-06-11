#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;
using ll=int64_t;

int main() {
  vector<ll> ABC(3);
  rep(i,0,3) cin >>ABC[i];
  sort(ABC.begin(),ABC.end());
  ll temp=ABC[2]/2;
  ll ans=ABC[0]*ABC[1]*(ABC[2]-temp)-ABC[0]*ABC[1]*temp;
  cout <<ans <<endl;
  return 0;
}
