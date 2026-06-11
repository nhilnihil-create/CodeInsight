#include<iostream>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  int A[7]={1,3,5,7,8,10,12};
  int B[4]={4,6,9,11};
  int C[1]={2};
  for(int i=0;i<=6;i++){
  
    if(x==A[i]){
    
      for(int j=i+1;j<=6;j++){
      
        if(A[j]==y){
        
          cout<<"Yes";
          return 0;
        }
      }
    }
  }
  for(int i=0;i<=3;i++){
  
    if(x==B[i]){
    
      for(int j=i+1;j<=3;j++){
      
        if(B[j]==y){
        
          cout<<"Yes";
          return 0;
        }
      }
    }
  }
  if(x==2&&y==2){
  
    cout<<"Yes";
    return 0;
  }
  cout<<"No";
  return 0;
}