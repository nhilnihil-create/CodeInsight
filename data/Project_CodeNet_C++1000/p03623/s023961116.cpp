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
  ll x,a,b;
  cin >> x >> a >> b;
  if(abs(x-a)<abs(x-b)) {
    cout << "A" << endl;
  }
  else {
    cout << "B" << endl;
  }
}