#include <bits/stdc++.h>

using namespace std;
int main(){
  int n;
   cin >> n;
  
  int sum=0;
  int index;
  for(int i=1;;i++){
   sum+=i;
    if(sum>=n){ 
      index=i;
      break;
  }
  }
  
  
   for(int i=1;i<=index;i++){
   if(sum-n!=i) cout << i << endl;
   }
    
  
}