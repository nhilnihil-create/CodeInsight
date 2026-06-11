#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  ll w,a,b;
  cin >> w >> a >> b;
  ll ans=max(abs(a-b)-w,0LL);
  cout << ans << endl;
}