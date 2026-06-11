#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  string S;
  cin>>N>>S;
  int top=0,X=0;
  rep(i,N){
    if(S[i]=='I')X+=1;
    else X-=1;
    top=max(top,X);
  }
  cout<<top<<endl;
  return 0;
}