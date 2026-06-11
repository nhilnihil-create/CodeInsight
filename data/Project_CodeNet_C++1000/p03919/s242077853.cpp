#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;cin>>H>>W;
  bool fin = false;
  for(int i=1;i<=H;++i){
    for(char c='A';c<'A'+W;++c){
      string s; cin>>s;
      if(s=="snuke"){ cout<<c<<i;fin=true;break;}
    }
    if(fin){break;}
  }
}