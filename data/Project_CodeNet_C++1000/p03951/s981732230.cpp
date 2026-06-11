#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
int N;
  cin>>N;
  string s,t;
  int a;
  cin>>s>>t;
  for(int i=0;i<=N;i++){
    if(i<N){
    int judge=0;
    for(int j=0;j<N-i;j++){
      if(s[i+j]!=t[j]) judge++;
    }
      if(judge==0){
       a=s.substr(0,i).size();
       a+=t.size();
        i+=10000;
      }
  }
    else{
      a=s.size();
      a+=t.size();
    }
  }
  cout<<a<<endl;
  
  return 0;
}