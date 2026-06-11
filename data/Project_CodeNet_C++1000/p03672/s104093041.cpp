#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int start;
  if ((int)(S.length()) % 2 == 1){
    start = (int)(S.length()) - 1;
  }
  else{
    start = (int)(S.length()) - 2;
  }
  
  for (int i = start; i > 0; i -= 2){
    int num = 1;
    while (num <= i / 2){
      if (S.at(num - 1) != S.at(num - 1 + i / 2)){
        break;
      }
      num++;
    }
    
    if (num == i / 2 + 1){
      cout << i << endl;
      exit(0);
    }
  }
}