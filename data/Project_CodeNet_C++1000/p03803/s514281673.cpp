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
  ll a,b;
  cin >> a >> b;
  a=(a+11)%13;
  b=(b+11)%13;
  if(a<b) cout << "Bob" << endl;
  else if(a>b) cout << "Alice" << endl;
  else cout << "Draw" << endl;
}