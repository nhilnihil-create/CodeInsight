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
  string s;
  cin >> s;
  ll n=s.size();
  for(ll i=0;i<n;i++) {
    if(i%2==0) cout << s[i];
  }
  cout << endl;
}