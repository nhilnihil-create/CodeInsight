#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  int g=0,p=0;
  int ans=0;
  rep(i,s.size()){
    if(s[i]=='g'){
      if(p<g){
        ans++;
        p++;
      }else g++;
    }else{
      if(p<g){
        p++;
      }else{
        ans--;
        g++;
      }     
    }
  }
  cout<<ans<<endl;
}