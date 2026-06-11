#include <bits/stdc++.h>
using namespace std;


int main() {
  int A,B,C;
  string ans="No";
  
  cin >> A >> B >> C;
  
  if(C>=A && C<=B){
  ans = "Yes";
  }
  
  cout << ans<<endl;
  
}