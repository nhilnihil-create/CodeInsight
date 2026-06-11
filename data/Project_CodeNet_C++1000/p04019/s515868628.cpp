#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  int Ncount=0;
  int Scount=0;
  int Ecount=0;
  int Wcount=0;
  for(size_t i=0;i<=S.length()-1;i++){
  
    if(S[i]=='N')Ncount++;
    if(S[i]=='S')Scount++;
    if(S[i]=='E')Ecount++;
    if(S[i]=='W')Wcount++;
  }
  if((Ncount==0&&Scount!=0)||(Ncount!=0&&Scount==0)){
  
    cout<<"No";
    return 0;
  }
  if((Ecount==0&&Wcount!=0)||(Ecount!=0&&Wcount==0)){
  
    cout<<"No";
    return 0;
  }
  cout<<"Yes";
  return 0;
}