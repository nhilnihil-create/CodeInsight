#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  string S;
  cin >> S;
  
  int size = S.size();
  int num = 0;
  bool ok = false;

  
  size = (size-1) / 2 * 2;
 
  for (int i = size; i > 0; ) {
  	int count = 0;
    
    for (int j = 0; j < i/2; j++) {
      if(S[j] != S[i/2 + j])
        break;
      if(j == i/2 - 1 && S[j] == S[i/2 + j])
        ok = true;
    }
    
    if(ok == true){
      num = i;
      break;
    }
    
    i = i - 2;
  }
  
  cout << num << endl;
  
  /*
  if(num > 0){
    cout << num << endl;
  }else {
    num = 1;
    cout << num << endl;
  }*/
  
 
}