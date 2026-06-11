#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b; cin>>a>>b;
  if(abs(a)==abs(b)){
    if(a!=b)cout<<1<<endl;
    else cout<<0<<endl;
  }
  else if(abs(a)<abs(b)){
    int ans=0;
    if(a<0)ans++;
    if(b<0)ans++;
    cout<<ans+abs(b)-abs(a)<<endl;
  }
  else{
    int ans=0;
    if(a>0)ans++;
    if(b>0)ans++;
    cout<<ans+abs(a)-abs(b)<<endl;
  }
}
