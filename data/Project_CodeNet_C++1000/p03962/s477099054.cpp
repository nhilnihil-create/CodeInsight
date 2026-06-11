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
  set<ll> cnt;
  for(ll i=0;i<3;i++) {
    ll tmp;
    cin >> tmp;
    cnt.insert(tmp);
  }
  cout << cnt.size() << endl;
}