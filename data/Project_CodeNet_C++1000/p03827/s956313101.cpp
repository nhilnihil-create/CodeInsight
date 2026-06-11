#include<iostream>
using namespace std;
int main(){
  int x=0;
  int ans=0;
  int n; cin>>n;
  string s; cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='I'){
      x+=1;
    }
    if(s[i]=='D'){
      x-=1;
    }
    if(x>ans)ans=x;
  }
  cout<<ans<<endl;
}
