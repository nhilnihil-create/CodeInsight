#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec p(n);
  for(ll i=0;i<n;i++) {
    cin >> p[i];
    p[i]--;
  }
  vec a(n);
  vec b(n);
  for(ll i=0;i<n;i++) {
    a[i]=(i+1)*30000;
    b[i]=(n-i)*30000;
  }
  for(ll i=0;i<n;i++) {
    a[p[i]]+=i;
  }
  for(ll i=0;i<n;i++) {
    if(i!=0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
  for(ll i=0;i<n;i++) {
    if(i!=0) {
      cout << " ";
    }
    cout << b[i];
  }
  cout << endl;
}