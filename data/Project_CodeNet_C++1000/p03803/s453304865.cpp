#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a, b;
  cin >> a >> b;
  if(a==1) a+=13;
  if(b==1) b+=13;
  
  string ans;
  if(a==b) ans = "Draw";
  else if(a>b) ans = "Alice";
  else ans = "Bob";
  cout << ans << endl;
  return 0;
}