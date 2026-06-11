#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int64_t s1 = a * b;
  int64_t s2 = c * d;
  
  if(s1 == s2){
    cout << s1 << endl;
  }
  else{
    cout << max(s1, s2) << endl;
  }
  
  


}
             