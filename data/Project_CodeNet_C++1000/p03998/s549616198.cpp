#include<bits/stdc++.h>
using namespace std;

int main(){
  string X,Y,Z;cin>>X>>Y>>Z;
  int lx=X.size();
  int ly=Y.size();
  int lz=Z.size();
  int p=1,q=0,r=0;
  char S=X.at(0);
  char ans;
  while(true){
    if(lx==1 && S=='a'){
      ans='A';
      break;
    }
    if(S=='a'){
      S=X.at(p);
      p++;
    }
    else if(S=='b'){
      S=Y.at(q);
      q++;
    }
    else{
      S=Z.at(r);
      r++;
    }
    if(S=='a'&&p==lx){
      ans='A';
      break;
    }
    else if(S=='b' && q==ly){
      ans='B';
      break;
    }
    else if(S=='c' && r==lz){
      ans='C';
      break;
    }
  }
  cout<<ans<<endl;
}
    
