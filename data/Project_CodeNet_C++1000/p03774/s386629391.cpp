#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;cin>>N>>M;
  vector<int> A(N),B(N),C(M),D(M);
  for(int i=0;i<N;i++) cin>>A.at(i)>>B.at(i);
  for(int i=0;i<M;i++) cin>>C.at(i)>>D.at(i);
  vector<int> ans;
  for(int i=0;i<N;i++){
    int count;
    int X=1000000000;
    for(int j=0;j<M;j++){
      int Y=abs(A.at(i)-C.at(j))+abs(B.at(i)-D.at(j));
      if(X>Y){
        count=j+1;
        X=Y;
      }
    }
    ans.push_back(count);
  }
  for(int i=0;i<N;i++) cout<<ans.at(i)<<endl;
}
    
