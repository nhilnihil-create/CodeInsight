#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int N;cin>>N;
  vector<long> A(3*N);
  for(int i=0;i<3*N;i++) cin>>A.at(i);
  sort(A.begin(),A.end());
  long ans=0;
  for(int i=1;i<=N;i++) ans+=A.at(3*N-2*i);
  cout<<ans<<endl;
}
    
