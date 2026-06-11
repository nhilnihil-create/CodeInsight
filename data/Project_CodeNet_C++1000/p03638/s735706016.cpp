#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int H,W,N;
  cin>>H>>W>>N;
  vector<int> A(H*W);
  int j=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    for(int k=0;k<a;k++)
      A[j+k]=i+1;
    j+=a;
  }
  vector<vector<int>> B(H,vector<int>(W));
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      if(i%2==0)
        B[i][j]=A[i*W+j];
      else
        B[i][W-j-1]=A[i*W+j];
    }
  for(vector<int> i:B){
    for(int j:i)
      cout<<j<<' ';
    cout<<endl;
  }
}