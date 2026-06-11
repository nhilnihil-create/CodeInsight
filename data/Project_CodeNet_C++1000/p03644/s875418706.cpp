#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  for(int i=0;i<7;i++){
    
    if( pow(2,i) <= n && n < pow(2,i+1) ){
      cout << pow(2,i) << endl;
      break;
    }
    
  }
}