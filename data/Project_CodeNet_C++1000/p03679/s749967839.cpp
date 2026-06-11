#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  ll x,a,b;
  cin >> x >> a >> b;
  if(a>=b) cout << "delicious" << endl;
  else if(b-a<x+1)cout << "safe" << endl;
  else cout << "dangerous" << endl;
}