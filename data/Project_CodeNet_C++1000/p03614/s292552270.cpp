#include<iostream>
#include<vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int N,a[100010],ans =0;
  
  cin >> N;
  
  for(int i=1;i<=N;i++)
    cin >> a[i];
  
  
  for(int i=1;i<=N;i++){
    
    if(a[i] == i){
      
      if(a[i+1] == i+1){
      ans ++;
      i++;
      }
      
      else{
        ans ++;
      }
      
    }
    
  }
    cout << ans << endl;
    
  }
    
    
      
    
        
    
      
        
      
      
      
      
  
 
