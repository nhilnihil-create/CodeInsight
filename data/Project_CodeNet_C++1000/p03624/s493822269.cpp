#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  string S;
  cin>>S;
  string E="abcdefghijklmnopqrstuvwxyz";
  rep(i,26){
    bool ja=true;
    rep(j,S.length()){
      if(S[j]==E[i]){
        ja=false;
      }
    }
    if(ja){
      cout<<E[i]<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}   