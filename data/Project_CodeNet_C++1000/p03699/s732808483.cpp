#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> S(N);
  for(int i=0;i<N;i++) cin>>S.at(i);
  sort(S.begin(),S.end());
  int sum=0;
  for(int i=0;i<N;i++) sum+=S.at(i);
  int ans;
  if(sum%10==0){
    ans=0;
    for(int j=0;j<N;j++){
      int X=sum-S.at(j);
      if(X%10!=0){
        ans=X;
        break;
      }
    }
  }
  else ans=sum;
  cout<<ans<<endl;
}
  