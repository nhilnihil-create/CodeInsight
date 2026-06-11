#include <bits/stdc++.h>
using namespace std;

//#define plong pair<long,long>;
using plong=pair<long,long>;

int main(){
  int N;cin>>N;
  long K;cin>>K;
  vector<plong> A(N);
  for(int i=0;i<N;i++){
    long X,Y;cin>>X>>Y;
    A.at(i)=make_pair(X,Y);
  }
  sort(A.begin(),A.end());
  int X=0;
  long count=0;
  int ans=1;
  while(true){
    while(true){
      if(A.at(X).first!=ans) break;
      count+=A.at(X).second;
      if(count>=K) break;
      X++;
    }
    if(count>=K) break;
    ans++;
  }
  cout<<ans<<endl;
}
  
