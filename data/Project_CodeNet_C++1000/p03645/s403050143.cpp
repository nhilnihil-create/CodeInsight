#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M; cin>>N>>M;
  vector<int>A(M,200001);
  vector<int>B(M,-1);
  for(int i=0;i<M;i++){
    int a,b; cin>>a>>b;
    if(a==1)A[i]=b;
    if(b==N)B[i]=a;
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  for(int i=0;i<M;i++){
    if(A[i]==200001)break;
    if(binary_search(B.begin(),B.end(),A[i])){cout<<"POSSIBLE"<<endl;return 0;}
  }
  cout<<"IMPOSSIBLE"<<endl;
}