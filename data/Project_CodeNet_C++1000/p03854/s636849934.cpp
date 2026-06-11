#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main() {
  string s;cin >> s;
  reverse(s.begin(),s.end());
  vector<string> v = {"maerd","remaerd","esare","resare"};

  string t = "";
  rep(i,s.size()){
    t.push_back(s.at(i));
    if( count(v.begin(),v.end(),t) ) t = "";
  }
  if( t == "" )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}