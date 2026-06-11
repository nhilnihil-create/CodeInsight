#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);vector<int>O((N+1)/2);vector<int>E(N/2);
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(i%2==0)O[i/2]=A[i];
    else E[i/2]=A[i];
  }
  sort(A.begin(),A.end());sort(O.begin(),O.end());sort(E.begin(),E.end());
  int o=0,e=0;
  for(int i=0;i<N;i++){
    if(i%2==0){
      for(int j=0;j<(N+1)/2;j++){
        if(A[i]==O[j])break;
        if(A[i]<O[j]){o++;break;}
        if(j==(N+1)/2-1)o++;
      }
    }
  }
  cout<<o<<endl;
}