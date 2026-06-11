#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
 
int main(){
 
  int n,a[310][310];
  cin >> n;
  
  for(int i=0;i<n;i++){
  for(int j=0;j<n;j++)
    cin >> a[i][j];
     
  }
  
  bool b[310][310];
    
  long long int ans = 0;
 
  for (int k = 0; k < n; k++){       
    for (int i = 0; i < n; i++) {    
      for (int j = 0; j < n; j++) {  
        
      if( a[i][j] > a[i][k] + a[k][j]){
        cout << " -1" << endl;
        return 0;
      }
        
       if( a[i][j] == a[i][k] + a[k][j] && a[i][k] > 0 && a[k][j]>0){
         b[i][j] = true;
       }
        
      }
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if( b[i][j] == false) ans += a[i][j];
    }
  }
  
 cout << ans << endl;
}
