#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N,M;
  cin>>N>>M;
  vector<int>ans(N,0);
  vector<int>A(M);
  vector<int>B(M);
  for(int i=0;i<=M-1;i++){
  
    cin>>A[i];
    ans[A[i]-1]++;
    cin>>B[i];
    ans[B[i]-1]++;
  }
  for(int i=0;i<=N-1;i++){
  
    cout<<ans[i]<<endl;
  }
  return 0;
}