#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  ll n, m;
  cin >> n >> m;
  m /= 2;
  ll ans = min(n, m);
  m -= n;
  if(m > 0) ans += m / 2;
  cout << ans << endl;
}