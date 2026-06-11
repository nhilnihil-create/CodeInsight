#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,M; cin>>N>>M;
  vector<pair<int,int>>A(N);
  for(int i=0;i<N;i++){
    int a,b; cin>>a>>b;
    A[i].first=a;
    A[i].second=b;
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    if(A[i].second>=M){cout<<A[i].first<<endl; return 0;}
    M-=A[i].second;
  }
}