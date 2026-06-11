#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<(int)c;i++)
#define print(var) cout<<var<<endl;
#define DEBUG(var) cerr<<var<<endl;
// puts("str");

const int inf = 1000000000;//10^9

int main (){
  string S;
  int K;
  cin >>S;
  cin >>K;
  rep(i,S.size()){
    if(S[i]!='a'&&('z'-S[i]+1<=K)){
      K-='z'-S[i]+1;
      S[i]='a';
    }
  }
  K=K%26;
  S[S.size()-1]+=K;
  if(S[S.size()-1]>'z'){
    S[S.size()-1]-=26;
  }
  print(S);


  return 0;

}
