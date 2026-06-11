#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  
  string ans;
  if(a * b <= 0) ans = "Zero";
  else if(a > 0) ans = "Positive";
  else if(a%2 == b%2) ans = "Negative";
  else ans = "Positive";
  
  cout << ans << endl;
}
