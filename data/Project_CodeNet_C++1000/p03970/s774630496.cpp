#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main()  {
  string s ; 
  string S = "CODEFESTIVAL2016"  ; 
  cin >> s ;
  int ans = 0 ; 
  
  rep(i,s.size()){
    if(s.at(i) != S.at(i) ) ans ++ ;
  }
  
  cout << ans ;
  
}
