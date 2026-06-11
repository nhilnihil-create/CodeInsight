#include <bits/stdc++.h>
using namespace std;
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int n,x;cin>>n>>x;
  if(x==1||x==2*n-1)fin("No");
  cout<<"Yes"<<endl;
  int cnt=2;
  for(int i=0;i<(2*n-1-3)/2;i++){
    if(cnt==x)cnt++;
    cout<<cnt++<<endl;
  }
  cout<<1<<endl<<x<<endl<<2*n-1<<endl;
  for(int i=0;i<(2*n-1-3)/2;i++){
    if(cnt==x)cnt++;
    cout<<cnt++<<endl;
  }
}
