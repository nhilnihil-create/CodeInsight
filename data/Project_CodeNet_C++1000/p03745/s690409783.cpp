#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n ; 
  cin >> n ; 
  bool UP   = false ;
  bool DOWN = false ;
  int ans =  0 ;
  vector<int> v(n) ;
  rep(i,n) cin >> v.at(i) ;
  
  rep(i,n-1){
    if( !UP && !DOWN){
      if(v.at(i) > v.at(i+1)) DOWN = true ;
      if(v.at(i) < v.at(i+1)) UP   = true ;
    }
    if(UP){
      if(v.at(i) > v.at(i+1)){
        ans ++ ;
        UP = false ;
      }
    }
    if(DOWN){
      if(v.at(i) < v.at(i+1)){
        ans ++ ;
        DOWN = false ;
      }
    }
  }
    cout << ans + 1  << endl ;
    
  

}