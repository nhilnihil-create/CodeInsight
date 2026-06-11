#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,sum=0,ans=1;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  sort(A.begin(),A.end());
  for(int i=0;i<N-1;i++){
    sum+=A[i];
    if(sum*2>=A[i+1])ans++;
    else ans=1;
  }
  cout<<ans<<endl;
}