#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<bool>A(N,false);
  A[0]=true;
  vector<int>B(N,1);
  for(int i=0;i<M;i++){
    int a,b; cin>>a>>b;
    a--;b--;
    if(A[a]==true){
      if(B[a]==1)A[a]=false;
      A[b]=true;
    }
    if(B[a]!=0){B[a]--;B[b]++;}
  }
  int ans=0;
  for(int i=0;i<N;i++)if(A[i]==true)ans++;
  cout<<ans<<endl;
}