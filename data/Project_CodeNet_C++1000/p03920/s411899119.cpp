#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int main (){
  
  long long int a;
 
  
  
  cin >>a ;
  int i=0;
 for(;i*(i+1)<2*a;i++);
  int b = i*(i+1)/2-a;
  for(int j=1;j<=i;j++){
    if(j-b !=0)cout << j << endl;
    //三角数の総和から足りないあまりの数字を引く方が最小を作れる。//
  }
  return 0;
}
