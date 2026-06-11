#include <bits/stdc++.h>
using namespace std;

const int64_t MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  
  string S,T;
  cin>>S>>T;

  int64_t ans=0;
  int st=0;
  if(S[0]==T[0]){
    ans=3;
    st=1;
  }
  else{
    ans=6;
    st=2;
  }

  for(int i=st;i<N;++i){
    
    if(S[i]==T[i] && S[i-1]==T[i-1]){
      ans *= 2;
      ans %= MOD;
    }
    else if(S[i]!=T[i] && S[i-1]==T[i-1]){
      ans *= 2;
      ans %=MOD;
      ++i;
    }
    else if(S[i]!=T[i] && S[i-1]!=T[i-1]){
      ans *=3;
      ans %= MOD;
      ++i;
    }
    
  }

  cout<<ans<<endl;
}