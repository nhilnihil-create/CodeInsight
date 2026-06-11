#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  cin>>s;
  string alpha="abcdefghijklmnopqrstuvwxyz";
  int ans=10000;
  int count=0;
  string k,q;
  for(int al=0;al<26;al++){
    k=s;
    count=0;
    for(int i=0;i<100;i++){
      q="";
      if(k.size()==1){
        break;
      }
      for(int j=0;j<k.size()-1;j++){
        if(k[j]!=k[j+1]){
          goto skip;
        }
      }
      break;
      skip:
      for(int i=0;i<k.size()-1;i++){
        if(k[i]==alpha[al]||k[i+1]==alpha[al]){
          q+=alpha[al];
        }
        else{
          q+=k[i];
        }
      }
      count++;
      k=q;
    }
    ans=min(ans,count);
  }
  cout<<ans<<endl;    
}