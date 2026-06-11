#include <bits/stdc++.h>
using namespace std;

int main(void){
 
  int X,t;
  cin >> X >> t;
  
  X -= t;
  if(X < 0) X = 0;
  cout << X <<endl;
}