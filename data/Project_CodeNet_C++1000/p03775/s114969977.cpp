#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long n;
  cin >> n;
  string s;
  int a = (int)sqrt(n);
  for(int i = a;i >= 1;i--){
    if(n % i == 0){
      s = to_string(n/i);
      cout << s.size() << endl;
      break;
    }
  }
  return 0;
}
