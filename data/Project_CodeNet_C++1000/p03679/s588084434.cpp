#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b,c;
  cin >> a >> b >> c;
  
  if( b >= c ){
    
    cout << "delicious" << endl;
    
    
  }
  
  else if( b < c && a >= c-b ){
    
    cout << "safe" << endl;
    
  }
  
  else{
    
    cout << "dangerous" << endl;
    
  }
  
}
