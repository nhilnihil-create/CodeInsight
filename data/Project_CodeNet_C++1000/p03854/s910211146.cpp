#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  string ip;
  
  cin>>ip;
  ll n=ip.length();
  bool isPossible=false;
  string pattern[4];
  pattern[0]="maerd";
  pattern[1]="remaerd";
  pattern[2]="esare";
  pattern[3]="resare";
  
  ll i=n-1;
  string temp="";
  while(i>=0){
    temp+=ip[i];
    bool found=false;
    for(int j=0;j<4&&!found;j++){
      if(temp==pattern[j]){
        found=true;
        temp="";
      }
    }
    i--;
  }
  
  if(temp==""){
    isPossible=true;
  }
  
  if(isPossible){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  
  return 0;
}
