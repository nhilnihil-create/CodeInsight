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
  vec a={0,1,0,2,0,2,0,0,2,0,2,0};
  ll x,y;
  cin >> x >> y;
  x--,y--;
  if(a[x]==a[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}