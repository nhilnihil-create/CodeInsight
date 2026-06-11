#include<bits/stdc++.h>

using namespace std;

int main(void){
  int n;
  cin >> n;
  bool ok = false;
  
  int temp = n;
  while(temp > 0){
    if(temp % 10 == 9) ok = true;
    temp /= 10;
  }
  
  cout << (ok ? "Yes" : "No") << endl;
}