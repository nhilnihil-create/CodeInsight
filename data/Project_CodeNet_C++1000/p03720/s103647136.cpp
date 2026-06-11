#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;cin>>N>>M;
  vector<int> A(N+1,0);
  for(int i=0;i<M;i++){
    int S,T;cin>>S>>T;
    A.at(S)++;
    A.at(T)++;
  }
  for(int i=1;i<=N;i++) cout<<A.at(i)<<endl;
}
  
