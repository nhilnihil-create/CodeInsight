#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  ll n;
  n = s.size();
  rep(i,26){
    bool have = false;
    rep(j,n){
      if(s[j] == (char)(97+i)){
        have = true;
      }
    }
   if(!have){
     cout << (char)(97+i);
     return 0;
   }
  }
  cout << "None";
  
    
  return 0;
}


