#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
2^10000
仮定して進めて行くんだけど、最初の4通りくらい？
あとは五月雨式に決まっていくかな
2文字確認かな
*/
int main(){
  ll N; cin>>N;
  string S; cin>>S;
  char ans[100010];
  string test[4]={"SS","SW","WS","WW"};
  for(ll i=0; i<4; i++){
    for(ll j=0; j<2; j++) ans[j]=test[i][j];
    for(ll j=1; j<=N; j++){
      ll jj=(j>=N)?j-N:j;
      if(ans[j]=='S' && S[jj]=='o' || ans[j]=='W' && S[jj]=='x') ans[j+1]=ans[j-1];
      else ans[j+1]=(ans[j-1]=='S')?'W':'S';
    }
    if(ans[0]!=ans[N] || ans[1]!=ans[N+1]) continue;    
    for(ll i=0; i<N; i++)cout<<ans[i];
    cout<<endl;
    return 0;
  }
  cout<<-1<<endl;
}