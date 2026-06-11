#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a, b;
  cin >> a >> b;
  if(a == 0 || b == 0){
    cout << "Zero" << endl;
    return 0;
  }
  if(a > 0 && b > 0){
    cout << "Positive" << endl;
    return 0;
  }
  if(a < 0 && b > 0){
    cout << "Zero" << endl;
    return 0;
  }
  if(a < 0 && b < 0){
    if((b - a) % 2 == 0){
      cout << "Negative" << endl;
      return 0;
    }
    if((b - a) % 2 == 1){
      cout << "Positive" << endl;
      return 0;
    }
  }
  return 0;
}