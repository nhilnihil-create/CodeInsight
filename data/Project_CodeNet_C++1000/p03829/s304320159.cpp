#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,A,B;
  cin>>N>>A>>B;

  int64_t X[N];
  for(int i=0;i<N;++i) cin>>X[i];

  int64_t ans=0;
  for(int i=0;i<N-1;++i){
    if(B>A*(X[i+1]-X[i])) ans += A*(X[i+1]-X[i]);
    else ans += B;
  }

  cout<<ans<<endl;
}