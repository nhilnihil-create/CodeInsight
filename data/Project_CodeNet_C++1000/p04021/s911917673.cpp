#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  map<int,int>M;
  vector<int>A(N);
  for(int i=0;i<N;i++){
  int a;cin>>a;
    A[i]=a;M[a]=i;
  }sort(A.begin(),A.end());
  int ans=0;
  for(int i=0;i<N;i++){
  int b=M.at(A.at(i));
    if(b%2!=i%2)
      ans++;
  }cout<<ans/2<<endl;
  return 0;
}