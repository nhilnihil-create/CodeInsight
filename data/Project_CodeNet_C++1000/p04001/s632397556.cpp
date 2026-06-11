#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  ll ans = 0;
  int cnt = 0;
  string s;
  cin >> s;
  int n = s.size();
  vector<string> ss;
  
  BREP(bit,n-1){
    cnt++;
    string s1;
    int ii = 0;
    REP(i,n){
      s1.push_back(s[ii]);
      if (bit & (1<<i)) {
        s1.push_back('+');
      }
      ii++;
    }
    ss.push_back(s1);
  }
  
  int cnts = 0;
  
  REP(i,cnt){
    string sc;
    int m = ss[i].size();
    int ii = 0;
    while(1){
      if(ss[i][ii] == '+'){
        ll nn = atoll(sc.c_str());
        ans += nn;
        sc = "";
      }
      else{
        sc.push_back(ss[i][ii]);
      }
      ii++;
      if(ii == m) break;
    }
    ll nn = atoll(sc.c_str());
    ans += nn;
      
  }

  
  cout << ans << endl;
  
  
  
  

}