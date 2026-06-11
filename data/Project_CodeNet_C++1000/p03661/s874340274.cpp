#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


long long int a,b=1000000000000007,c[200010],d[200010],ans =0,ant=0,anu =0;

int main(){
  cin >> a ;
  
  for(int i=0;i<a;i++)
    cin >> c[i];
  
  for(int i=0;i<a;i++){
    
   ant += c[i];
  }
  
  for(int i=0;i<a-1;i++){
    anu += c[i];
  b = min(b,abs(ant -2*anu));
  }
  
  cout << b << endl;
}
