#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

ll check(string a,string b) {
  ll na=a.size();
  ll nb=b.size();
  if(na>nb) return 1;
  if(na<nb) return 0;
  for(ll i=0;i<na;i++) {
    if(a[i]>b[i]) return 1;
    if(a[i]<b[i]) return 0;
  }
  return 0;
}

int main() {
  string a,b;
  cin >> a >> b;
  if(check(a,b)) {
    cout << "GREATER" << endl;
  }
  else if(check(b,a)) {
    cout << "LESS" << endl;
  }
  else {
    cout << "EQUAL" << endl;
  }
}