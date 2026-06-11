#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n,m;
  cin >> n >> m ;
  vector<vector<char>> A(n,vector<char> (n));
  vector<vector<char>> B(n,vector<char> (m));
  string ans = "No" ;
  
  rep(i,n){
    rep(j,n){
      cin >> A.at(i).at(j) ;
    }
  }
  
  rep(i,m){
    rep(j,m){
      cin >> B.at(i).at(j);
    }
  }
  

  
  rep(i,n-m+1){
    rep(j,n-m+1){
      bool OK = true ;
      rep(k,m){
        rep(l,m){
          if(A.at(i+k).at(j+l) != B.at(k).at(l)) OK = false ;
        }
      }
      if(OK){
        ans = "Yes";
        break;
      }
    }
  }
       
      
  cout << ans ;
  
}
