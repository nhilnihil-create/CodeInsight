#include <bits/stdc++.h>

using namespace std;

int sx, sy, tx, ty;

int main(){
  cin>>sx>>sy>>tx>>ty;

  string ans="";

  for(int i=0; i<tx-sx; i++) ans+='R';
  for(int i=0; i<ty-sy; i++) ans+='U';
  
  for(int i=0; i<ans.size(); i++){
    if(ans[i]=='R') ans+='L';
    else if(ans[i]=='U') ans+='D';
  }
  
  string ans2="";
  ans2+='D';

  for(int i=0; i<tx+1-sx; i++) ans2+='R';
  for(int i=0; i<ty+1-sy; i++) ans2+='U';

  ans2+='L';
  ans2+='U';

  for(int i=0; i<tx+1-sx; i++) ans2+='L';
  for(int i=0; i<ty+1-sy; i++) ans2+='D';

  ans2+='R';

  cout<<ans+ans2<<endl;
}
