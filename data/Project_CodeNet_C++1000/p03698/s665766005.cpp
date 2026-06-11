#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int A[26];
  rep(i,26)A[i]=0;
  rep(i,S.size())A[S[i]-'a']+=1;
  for(int j:A){
    if(j>=2){
      cout<<"no"<<endl;
      return 0;
    }
  }
  cout<<"yes"<<endl;
  return 0;
}