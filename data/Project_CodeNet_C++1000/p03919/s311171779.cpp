#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int main (){
  
  long long int a,b;
  char d,e;
  string c[30][30];
  
  
  cin >>a >>b ;
  for(int i=0;i<=a;i++){
    for(int j=0;j<b;j++)
  cin >> c[i][j];
    
  }
  d ='A';
  for(int i=0;i<=a;i++){
    for(int j=0;j<b;j++)
      if( c[i][j] == "snuke"){
        d += j;
        cout << d<<i+1<< endl;
      }
  }
}
  
   
  
  
 
