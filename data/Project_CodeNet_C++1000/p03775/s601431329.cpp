#include <bits/stdc++.h>
using namespace std;

int GetDigit(long num){
    return log10(num)+1;
}

int main() {
  long  ans, divided_Num,i,Num,root_Num;
  
  cin >> Num;
  root_Num = floor(pow(Num,0.5));
  
  for(i = root_Num;i>0;i--){
    if(Num % i == 0){
      break;
    }
  }
  divided_Num = floor(Num / i);
  ans = GetDigit(divided_Num);
  cout << ans << endl;
}

 

  

  
  



