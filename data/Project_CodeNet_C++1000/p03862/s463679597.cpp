#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int64_t N,x,ans=0,zero=0; cin>>N>>x;
  vector<int64_t> A(N);
  rep(i,N) cin>>A.at(i);
  int64_t temp=A.at(0);
  if(temp>x){
    ans+=temp-x;
    temp=x;
  }
  for(int i=1;i<N;i++){
    if(A.at(i)+temp>x){
      ans+=A.at(i)-(x-temp);
      A.at(i)=(x-temp);
    }
    temp=A.at(i);
  }
  cout<<ans;
}
