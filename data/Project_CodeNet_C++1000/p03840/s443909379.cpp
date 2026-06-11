#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll i,o,t,j,l,s,z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  ll ans=0;
  ans+=o;
  ans+=i/2*2;
  ans+=j/2*2;
  ans+=l/2*2;
  if(i%2&&j%2&&l%2) ans+=3;
  if((i%2+j%2+l%2==2)&&i&&j&&l) ans++;
  cout << ans << endl;
}