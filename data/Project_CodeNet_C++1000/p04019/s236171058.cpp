#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S,ans="Yes";
  cin>>S;
  int A[4];
  rep(i,4)A[i]=0;
  rep(i,S.size()){
    if(S[i]=='N')A[0]+=1;
    if(S[i]=='E')A[1]+=1;
    if(S[i]=='S')A[2]+=1;
    if(S[i]=='W')A[3]+=1;
  }
  if(A[0]>=1&&A[2]==0)ans="No";
  if(A[2]>=1&&A[0]==0)ans="No";
  if(A[1]>=1&&A[3]==0)ans="No";
  if(A[3]>=1&&A[1]==0)ans="No";
  cout<<ans<<endl;
}