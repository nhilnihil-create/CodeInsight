#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<=(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  string s;
  cin>>s;
  sort(all(s));
  string t="abcdefghijklmnopqrstuvwxyz";
  rep(i,26){
    bool ja=true;
    rep(j,s.length()){
      if(s[j]==t[i]){
        ja=false;
      }
    }
    if(ja){
      cout<<t[i]<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}