#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll a,b;
  cin >> a >> b;
  if(a*b<=0) cout << "Zero" << endl;
  else if(0<a) cout << "Positive" << endl;
  else {
    if((b-a+1)%2) cout << "Negative" << endl;
    else cout << "Positive" << endl;
  }
}