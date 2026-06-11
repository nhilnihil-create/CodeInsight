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
  
  int A_MAX = 0 ;
  int A_MIN = INF ;
  int B_MIN = INF ;
  
  rep(i,n){
    int a , b ; 
    cin >> a >> b ;
    A_MAX = max(A_MAX,a) ;
    B_MIN = min(B_MIN,b) ;
  }
  
 
  cout << A_MAX + B_MIN  <<endl ;
  
  


}
