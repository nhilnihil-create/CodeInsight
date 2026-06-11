#include<bits/stdc++.h>

using namespace std;


int main(){
  long long int i,o,t,j,l,s,z ;
   cin >> i >> o >> t >> j >> l >> s >> z ;
  
  if(i > 0 && j > 0 && l > 0){

  long long int a = (i/2)*2+(j/2)*2+(l/2)*2;
  long long int b = ((i-1)/2)*2 + ((j-1)/2)*2 + ((l-1)/2)*2 + 3;
  long long int ans = max(a,b);
  
  cout << ans + o << endl;
  
}
  
  else{
    cout << (i/2)*2+(j/2)*2+(l/2)*2 + o << endl;
  }
  
}
  
 
