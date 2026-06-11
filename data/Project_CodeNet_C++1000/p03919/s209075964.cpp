#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;cin>>H>>W;
  char ans1; int ans2;
  string s;
  for(int i=0;i<H;i++){
    ans2=1+i;
    for(int j=0;j<W;j++){
      ans1='A'+j;
      cin>>s;
    if(s=="snuke")break;
    }
    if(s=="snuke")break;
  }
  cout<<ans1<<ans2<<endl;
}