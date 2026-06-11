#include<bits/stdc++.h>
using namespace std;
int main(){
  string M;cin>>M;bool N=false,W=false,S=false,E=false;
  for(int X=0;X<M.size();X++){
    if(M[X]=='N')N=true;
    if(M[X]=='W')W=true;
    if(M[X]=='S')S=true;
    if(M[X]=='E')E=true;
  }
  if(S==N&&E==W)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}