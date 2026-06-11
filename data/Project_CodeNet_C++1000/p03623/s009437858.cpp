#include <bits/stdc++.h>
using namespace std;

int main(void){
 
  int x,A,B;
  cin >> x >> A >> B;
  
  if(abs(x-A) < abs(x-B)){
      cout << 'A' <<endl; 
  }
  else{
      cout << 'B' <<endl;
  }
}