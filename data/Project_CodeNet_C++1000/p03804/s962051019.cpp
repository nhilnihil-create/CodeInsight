#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b; cin>>a>>b;
  vector<vector<char>>A(a,vector<char>(a));
  vector<vector<char>>B(b,vector<char>(b));
  for(int i=0;i<a;i++){
    string S; cin>>S;
    for(int j=0;j<a;j++){
      A[i][j]=S.at(j);
    }
  }
  for(int i=0;i<b;i++){
    string S; cin>>S;
    for(int j=0;j<b;j++){
      B[i][j]=S.at(j);
    }
  }
  for(int i=0;i<a-b+1;i++){
    for(int j=0;j<a-b+1;j++){
      for(int k=0;k<b;k++){
        bool z=true;
        for(int l=0;l<b;l++){
          if(A[i+k][j+l]!=B[k][l])z=false;
        }
        if(z==false)break;
        if(k==b-1){cout<<"Yes"<<endl; return 0;}
      }
    }
  }
  cout<<"No"<<endl;
}