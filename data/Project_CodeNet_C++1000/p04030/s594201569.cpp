#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S,A;
  cin>>S;
  int Si=S.size();
  rep(i,Si){
    if(S[i]!='B'){
      A+=S[i];
    }else{
      if(A.size()==0)continue;
      A.pop_back();
    }
  }
  cout<<A<<endl;
  return 0;
}