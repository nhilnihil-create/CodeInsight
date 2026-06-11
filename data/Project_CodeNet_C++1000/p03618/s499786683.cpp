#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  cin>>s;
  ll ans=(s.size()*(s.size()-1))/2+1;
  string t="abcdefghijklmnopqrstuvwxyz";
  ll vec[26]={};
  for(int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
      if(s[i]==t[j]){
        vec[j]++;
      }
    }
  }
  for(int i=0;i<26;i++){
    ans-=(vec[i]*(vec[i]-1))/2;
  }
  cout<<ans<<endl;
}