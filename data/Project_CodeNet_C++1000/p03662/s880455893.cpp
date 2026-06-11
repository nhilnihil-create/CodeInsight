#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  vector<int> B(N,-1),C(N,-1);
  B[0]=C[N-1]=0;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int I=Q.front();
    Q.pop();
    for(int i:A[I])
      if(B[i]==-1){
        B[i]=B[I]+1;
        Q.push(i);
      }
  }
  Q.push(N-1);
  while(!Q.empty()){
    int I=Q.front();
    Q.pop();
    for(int i:A[I])
      if(C[i]==-1){
        C[i]=C[I]+1;
        Q.push(i);
      }
  }
  int a=0,b=0;
  for(int i=0;i<N;i++){
    if(B[i]<=C[i])a++;
    else b++;
  }
  puts(a>b?"Fennec":"Snuke");
}