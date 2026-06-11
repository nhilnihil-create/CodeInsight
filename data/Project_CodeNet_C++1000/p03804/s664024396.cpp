#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<string> A(N),B(M);
  for(string &s:A)
    cin>>s;
  for(string &s:B)
    cin>>s;
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool bo=false;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++)
          if(A[i+k][j+l]!=B[k][l]){
            bo=true;
            break;
          }
        if(bo)
          break;
      }
      if(bo)
        continue;
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}