#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  set<char> se;
  for(char c : s){
    se.insert(c);
  }
  if(se.size() == 1){
    cout << 0 << endl;
    return 0;
  }

  int ans = 1001001001;
  for(auto c : se){
    string ss = s;
    while(1){
      string nx;
      bool f = true;
      rep(i, ss.size()-1){
        if(ss.at(i) == c) nx.push_back(c);
        else{
          if(ss.at(i+1)== c) nx.push_back(c);
          else{
            nx.push_back(ss.at(i));
            f = false;
          }
        }
      }
      // if(c == 'a') cout << nx << endl;
      if(f == true){
        int add = s.size() - nx.size();
        ans = min(ans, add);
        break;
      }
      ss = nx;
    }
  }
  cout << ans << endl;
  return 0;
}