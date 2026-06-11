#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  set<char> se;
  rep(i, s.size()) se.insert(s.at(i));
  bool f = false;
  if(auto itr = se.find('N') != se.end()){
    if(se.find('S') == se.end()) f = true;
  }
  if(auto itr = se.find('S') != se.end()){
    if(se.find('N') == se.end()) f = true;
  }
  if(auto itr = se.find('W') != se.end()){
    if(se.find('E') == se.end()) f = true;
  }
  if(auto itr = se.find('E') != se.end()){
    if(se.find('W') == se.end()) f = true;
  }
  if(f == false) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}