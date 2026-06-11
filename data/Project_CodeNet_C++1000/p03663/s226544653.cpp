#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll change(string str){
  stringstream ss;
  ss<<str;
  ll res;
  ss>>res;
  return res;
}

int main(){
  char ch,ch2;
  string ans="", mini, maxm;
  string tmpMin="",tmpMax="";
  int I,d,cc=0;
  
  for(I=1;I<=11;I++){
    mini=maxm="";
   
    for(int i=0;i<I;i++)mini.push_back('0');
    mini[0]='1';
    for(int i=0;i<I;i++)maxm.push_back('9');
    
    cout<<"? "<<mini<<endl;
    cin>>ch;
    cout<<"? "<<maxm<<endl;
    cin>>ch2;
    
    if(ch2=='N'){
      if(tmpMin=="")cc=I;
    }
    
    if(ch=='Y'&&ch2=='Y'){
      d=I;
      tmpMin=mini;
      tmpMax=maxm;
    }
  }

  if(d==11){
    string ans="1";
    for(int i=0;i<cc;i++)ans.push_back('0');
    cout<<"! "<<ans<<endl;
    return 0;
  }
  
  ll L=change(tmpMin);
  ll R=change(tmpMax);
  ll M;
  
  while(L<R){
    M=(L+R)/2;
    cout<<"? "<<M*10<<endl;
    cin>>ch;
    if(ch=='N'){
      L=M+1;
    }else{
      R=M;
    }
  }

  cout<<"! "<<L<<endl;
  
  return 0;
}
