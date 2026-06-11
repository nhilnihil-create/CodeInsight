#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<pair<int64_t,int64_t>>C(N);
  for(int i=0;i<N;i++){
  int64_t T,A;
    cin>>T>>A;
    pair<int64_t,int64_t>p(T,A);
    C.at(i)=p;
  }int64_t x,y;
  x=1,y=1;
  for(int i=0;i<N;i++){
  int64_t T=C.at(i).first;
    int64_t A=C.at(i).second;
  int64_t a=max((x-1)/T,(y-1)/A);
    a++;
    x=T*a; y=A*a;
  }int64_t ans=x+y;
  cout<<ans<<endl;
     return 0;
}