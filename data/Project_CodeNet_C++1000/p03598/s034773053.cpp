#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k,a=0;
  cin>>n>>k;  
  
  for(int i=0;i<n;i++){
    int x;
    cin>>x;   
    int d;
    if(k-x<0){
      d=x-k;
    }
    else{
      d=k-x;
    }
   
    if(x<d){
      a+=(x*2);
    }
    else{
      a+=(d*2);
    }
  }
  cout<<a<<endl;
    
}