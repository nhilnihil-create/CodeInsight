#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,C,K;cin>>N>>C>>K;
  if(C==1){cout<<N<<endl;return 0;}
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(A.begin(),A.end());
  int ans=1,count=0,c=1;
  bool a=true;
  for(int i=1;i<N;i++){
    if(!a){ans++;c=1;a=true;}
    else{
      count+=A[i]-A[i-1];
      if(count>K){count=0;a=false;i--;continue;}
      c++;
      if(c==C){count=0;a=false;continue;}
    }
  }
  cout<<ans<<endl;
}