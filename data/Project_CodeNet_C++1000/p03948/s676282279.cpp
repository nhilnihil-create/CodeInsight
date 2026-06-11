#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int a, b , c[100010], x[100010];
  
  cin >> a >> b;
  
  for(int i=1;i<=a;i++)
    cin >> c[i];
  
  x[0] = 1e15;
  
  for(int i=1;i<=a;i++){
    x[i] = min(c[i] , x[i-1]);
  }
    int p = -1e9;
    int ans = 0;
  
  for(int i=1;i<=a;i++){
    
    if(c[i]-x[i] > p){
      p = c[i] - x[i];
      ans = 1;
    }
    
    else if(c[i] - x[i] == p){
      ans ++;
    }
    
  }
  
  cout << ans << endl;
  
}
      
      
