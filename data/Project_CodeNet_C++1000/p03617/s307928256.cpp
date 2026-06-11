#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;


int main(){
  ll ans = 0;
  vector<ll> cp(3);
  rep(i,3) cin >> cp[i];
  ll cp3; cin >> cp3;
  cp[0] *= 4; cp[1] *= 2; 
  int N; cin >> N; 
  sort(all(cp));  

  if(cp[0]*2 <= cp3) ans = cp[0]*N;
  else if(N%2 == 0) ans = (N/2)*cp3;
  else ans = (N-1)/2*cp3 + cp[0];
         
  cout << ans << endl;
  return 0;

}