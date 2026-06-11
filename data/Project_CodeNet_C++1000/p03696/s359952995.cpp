#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;cin>>n;
  string s;cin>>s;
  int v[n];
  for(int i=0;i<n;i++){
    if(s[i]=='(') v[i]=1;
    else v[i]=-1;
  }
  int tmp=0;
  for(int i=0;i<n;i++){
    tmp+=v[i];
    if(tmp<0){
      s='('+s;
      tmp=0;
    }
  }
  while(tmp>0){
    s=s+')';
    tmp--;
  }
  cout<<s<<endl;
  return 0;
}