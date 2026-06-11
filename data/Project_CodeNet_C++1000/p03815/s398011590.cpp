#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  ll x;
  cin >> x;
  ll ans = x / 11 * 2;
  if(x % 11 > 6) ans += 2;
  else if(x % 11 > 0) ans += 1;
  cout << ans << endl;
}