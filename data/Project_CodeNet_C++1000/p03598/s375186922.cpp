#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int ball;
  int a=0;
  int b;
  int x;
  int sum=0;
   
  cin >> ball >>b;
  
  for (int i = 0; i < ball; i++) {
   cin >>x;
    if(b-x<=x){
     sum+=2*(b-x); 
    }else{
      sum+=2*x;
     }
  }
  cout <<sum <<endl;}