#include<bits/stdc++.h>
using namespace std;
static const long long MOD=1000000007;

int main(){
  int N;
  cin>>N;
  string s1,s2,s3;
  cin>>s1>>s2;
  s3="";
  for(int i=0;i<N;i++){
    if(s1.at(i)==s2.at(i)){
      s3+="A";
    }
    else{
      s3+="B";
      i++;
    }
  }
  long long ans=1;
  int flag=0;
  for(int i=0;i<s3.size();i++){
    if(i==0 && s3.at(i)=='A'){
      ans=ans*3;
      flag=0;
      continue;
    }
    if(i==0 && s3.at(i)=='B'){
      ans=(ans*6);
      flag=1;
      continue;
    } 
    if(s3.at(i)=='A' && flag==0){
      ans=(ans*2)%MOD;
      continue;
    }
    if(s3.at(i)=='A' && flag==1){
      flag=0;
      continue;
    }   
    if(s3.at(i)=='B' && flag==0){
      ans=(ans*2)%MOD;
      flag=1;
      continue;
    }    
    if(s3.at(i)=='B' && flag==1){
      ans=(ans*3)%MOD;
      flag=1;
      continue;
    } 
  }
  cout<<ans<<endl;
  return 0;
}
 
    