#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long

int main() {
  int n ;
  cin >> n ;
  vector<int> v(n);
  int four = 0 ;
  int two  = 0;
  int no = n;
  string ans = "No";
  
  rep(i,n){
    cin>> v.at(i);
    if(v.at(i) % 4 == 0) four ++ ;
    if(v.at(i) % 2 == 0) two  ++ ;
  }
  
  no -= two ;
  two -= four;
  
  if(two == 0){
    if(four + 1 - no >= 0 ) ans ="Yes";
  }
  else 
    if(four >= no) ans ="Yes";
 
  
  cout <<ans ;

}
