#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
 vector<int> A(M);
 vector<int> B(M);
  for(int i=0;i<M;i++){
    cin>>A.at(i)>>B.at(i);
  }
 vector<int> C(N);
  for(int i=1;i<=N;i++){
   int sum=0;
    for(int j=0;j<M;j++){
      if(A.at(j)==i||B.at(j)==i){
        sum++;
      }
    }
    C.at(i-1)=sum;
  }
  for(int i=0;i<N;i++){
cout<<C.at(i)<<endl;
  }
}