#include<bits/stdc++.h>

using namespace std;


int main(){
   int n , x ;
   cin >> n >> x ;
  
  int ans =2,res = n;
  
  if(x == 1 || x == 2*n-1){
    cout << "No" << endl;
    
    return 0;
  }
   
  else{
    if(x < n){
      cout << "Yes" << endl;
    for(int i=0;i<n-2;i++){
      if(i+ans != x){
      cout << i+ans << endl;
    }
      else{
        ans++;
        cout << i+ans << endl;
      }
    }
    cout << "1" << endl;
    cout <<  x << endl;
    cout << 2*n-1 << endl;
      
    for(int i=0;i<n-2;i++){
      cout << i+n+1 << endl;
    }
      
    }
    else{
      cout << "Yes" << endl;
      
      for(int i=0;i<n-2;i++){
     
      cout << i+2 << endl;
    
      }
      
    cout << "1" << endl;
    cout <<  x << endl;
    cout << 2*n-1 << endl;
      
    for(int i=0;i<n-2;i++){
      if(i+res != x){
      cout << i+res << endl;
    }
      else{
        res++;
        cout << i+res << endl;
      }
    }
    }
  }
}
