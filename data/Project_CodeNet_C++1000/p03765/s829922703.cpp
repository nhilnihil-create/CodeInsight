#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S,T;
  int Q;
  cin>>S>>T>>Q;
  int N=S.size(),M=T.size();
  vector<int> A(N+1),B(M+1);
  for(int i=0;i<N;i++)A[i+1]=A[i]+(S[i]=='A'?1:2);
  for(int i=0;i<M;i++)B[i+1]=B[i]+(T[i]=='A'?1:2);
  while(Q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((A[b]-A[a-1])%3==(B[d]-B[c-1])%3)puts("YES");
    else puts("NO");
  }
}