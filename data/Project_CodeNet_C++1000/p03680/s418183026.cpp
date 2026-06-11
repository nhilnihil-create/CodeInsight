#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  int ans=0;
  int now=1;
  bool can=true;
  while(can){
    ans++;
    now=A.at(now-1);
    if(now==2) break;
    if(ans==100000000) can=false;
  }
  if(can) cout<<ans<<endl;
  else cout<<-1<<endl;
}
