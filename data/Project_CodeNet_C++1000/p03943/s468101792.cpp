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
  vec a(3);
  for(ll i=0;i<3;i++) cin >> a[i];
  sort(a.begin(),a.end());
  if(a[0]+a[1]==a[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
}