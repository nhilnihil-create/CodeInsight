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
  if(s[0]==s[s.size()-1]^s.size()%2) {
    cout << "First" << endl;
  }
  else cout << "Second" << endl;
}