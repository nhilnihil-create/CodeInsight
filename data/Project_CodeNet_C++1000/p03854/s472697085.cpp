#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  string s; cin >> s;
  reverse(s.begin(),s.end());
  
  vector<string> d = {"maerd", "remaerd", "esare", "resare"};
  ll p = 0; bool match;
  rep(i, s.size()){
    rep(j, 4){
      match = false;
      if(s.substr(p, d[j].size()) == d[j]){
        p += d[j].size();
        match = true;
        break;
      }
    }
    if(!match){
      cout << "NO" << endl;
      return 0;
    }
    if(p == s.size())
      break;
  }
  
  cout << "YES" << endl;
}
