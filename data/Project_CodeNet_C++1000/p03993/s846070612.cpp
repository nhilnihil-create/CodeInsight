#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>A(N);
  vector<int>key(N,0);
  int ans=0;
  int check=0;
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
  }
  for(int i=0;i<=N-1;i++){
  
    if(key[i]==0){
      
      check=A[i]-1;
      if(A[check]==i+1){
    
        key[i]=1;
        key[check]=1;
        ans++;
      }
    }
  }
  cout<<ans;
  return 0;
}