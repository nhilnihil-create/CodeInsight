#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int a;
  cin >> a;
  long long int b = a / 11;
  long long int ans = 0;
  if(a%11==0) ans = 2*b;
  else if(a%11<=6) ans = 2*b+1;
  else ans = 2*b + 2;
  cout << ans << endl;
  return 0;
}