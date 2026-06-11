#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A[3];
  rep(i,3)cin>>A[i];
  int P[101];
  rep(i,101)P[i]=0;
  rep(i,3)P[A[i]]+=1;
  int ans=0;
  rep(i,101){
    if(P[i]>0){
      ans+=1;
    }
  }
  cout<<ans<<endl;
}