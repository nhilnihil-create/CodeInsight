#include <bits/stdc++.h>
using namespace std;
#include <math.h>
char a[100][100];
char b[100][100];
int main() {
 int N,M;
 cin>>N>>M;
 for(int i=0;i<N;i++){
     for(int j=0;j<N;j++){
     cin>>a[i][j];
 }
 }
 for(int i=0;i<M;i++){
     for(int j=0;j<M;j++){
     cin>>b[i][j];
 }
 }
 bool match=false;
 for(int i=0;i<N;i++){
     for(int j=0;j<N;j++){
      if(i+M-1>=N||j+M-1>=N){continue;}
      bool ok=true;
      for(int k=0;k<M;k++){
          for(int t=0;t<M;t++){
           if(a[i+k][j+t]!=b[k][t]){ok=false;}
          }
      }
      if(ok){match=true;}
     }
 }
 if(match){cout<<"Yes"<<endl;}
 else{cout<<"No"<<endl;}
 return 0;}