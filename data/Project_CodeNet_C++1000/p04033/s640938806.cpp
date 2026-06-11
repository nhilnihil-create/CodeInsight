#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string ans = "Positive";
  
  int count=0;
  
  if(a<=0&&b>=0)ans="Zero";
  else if(b<0&&(b-a)%2==0)ans="Negative";
  
  cout << ans << endl;
  
}