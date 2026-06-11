#include<bits/stdc++.h>
using namespace std;


int main(){

  int af=0, bf=0, cf=0;
  string SA, SB, SC;
  cin >> SA >> SB >> SC;
  int la=SA.size(), lb=SB.size(), lc=SC.size();
  
  int  ix=af;
  char h ='a';
  
  while(true){
    
    if(h=='a'){
      if(af==la){
        cout<<'A'<<endl;
        return 0;
      }      
      h=SA[af];
      af++;
    }else if(h=='b'){
      if(bf==lb){
        cout<<'B'<<endl;
        return 0;
      }      
      h=SB[bf];
      bf++;      
    }else{
      if(cf==lc){
        cout<<'C'<<endl;
        return 0;
      }      
      h=SC[cf];
      cf++;      
    }
  }
  return 0;
}