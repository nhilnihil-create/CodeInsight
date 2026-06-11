#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b;
  char op;
  cin >> a >> op >> b;
  
  long long ans;
  if (op=='+'){
    ans = a+b;
  }
  else {
    ans =a-b;
  }
  
  cout << ans << endl;
}
    