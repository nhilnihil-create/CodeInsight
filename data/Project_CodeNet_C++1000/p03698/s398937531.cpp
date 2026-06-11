#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  string S;
  cin>>S;
  rep(i,S.length()){
    rep(j,i){
      if(S[i]==S[j]){
        cout<<"no"<<endl;
        return 0;
      }
    }
  }
  cout<<"yes"<<endl;
}