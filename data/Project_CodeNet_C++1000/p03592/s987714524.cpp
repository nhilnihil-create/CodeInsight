#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n,m,k;
  cin>>n>>m>>k; 
  int i,j;
  bool judge=false;
  
  for(i = 0;i <= n; i++){
    for(j = 0;j <= m; j++){
      if(i*m + j*n - 2*i*j == k){
        judge = true;
      }
    }
  }
  
  if(judge){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
}
