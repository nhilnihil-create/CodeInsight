#include<bits/stdc++.h>
using namespace std;
int64_t f(int64_t x,int64_t y){
int64_t m=min(x,y);
  int64_t M=max(x,y);
  if(M%m==0)
    return 2*M-m;
  else{
  return 2*(M/m)*m+f(m,M%m);
  }

}
int main(){
int64_t N,X;
  cin>>N>>X;
  int64_t ans=N+f(X,N-X);
  cout<<ans<<endl;
    return 0;
}