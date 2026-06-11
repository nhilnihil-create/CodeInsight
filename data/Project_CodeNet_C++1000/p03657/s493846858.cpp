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
  if(a%3==0||b%3==0||(a+b)%3==0) {
    cout << "Possible" << endl;
  }
  else cout << "Impossible" << endl;
}