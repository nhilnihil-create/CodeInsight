#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  while(1){
    int flag=0;
    if(S.length()==0){
      cout<<0<<endl;
      return 0;
    }
    for(int i=0;i<S.length()-1;i++){
      if(S.at(i)=='S' && S.at(i+1)=='T'){
        //cout<<i<<"#"<<endl;
        //cout<<S<<"before"<<endl;
        S.erase(i,1);
        S.erase(i,1);
        i--;
        i--;
        flag=1;
        //cout<<S<<"after"<<endl;
      }
    }


    if(flag==0) break;
  }
  //cout<<S<<endl;
  cout<<S.length()<<endl;
  return 0;
}

    
    