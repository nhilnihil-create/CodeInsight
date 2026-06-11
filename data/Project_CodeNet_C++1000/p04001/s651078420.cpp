#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ctoi(char c){
  if(c>='0'&&c<='9'){
    return c-'0';
  }
  return 0;
}

int main(){
  string s;
  cin>>s;
  int vecb[s.size()];
  ll ans=0;
  ll q=0;
  for(int bit=0;bit<(1<<s.size()-1);bit++){
    for(int i=0;i<s.size()-1;i++){
      if(bit&(1<<i)){
        vecb[i]=1;
      }
      else{
        vecb[i]=0;
      }
    }
    q=0;
    for(int i=0;i<s.size();i++){
      if(i==s.size()-1){
        q*=10;
        q+=ctoi(s[s.size()-1]);
        ans+=q;
        break;
      }
      if(vecb[i]==0){
        q*=10;
        q+=ctoi(s[i]);
      }
      else{
        q*=10;
        q+=ctoi(s[i]);
        ans+=q;
        q=0;
      }
    }
  }
  cout<<ans<<endl;
}