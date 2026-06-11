#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int N,K,m=0,M,w;bool x=true;cin>>N>>K;vector<long long int>a(N);
  for(long long int i=0;i<N;i++)cin>>a.at(i);
  for(long long int i=0;i<(1<<15);i++){
    bitset<16>p(i);
    if(p.test(N-1))break;
    w=a.at(0),M=0;
    if(p.count()>=K-1){
      for(long long int j=1;j<N;j++){
        if(p.test(j-1)){
          w=max(w+1,a.at(j));
          M+=w-a.at(j);
        }
        else if(w<a.at(j))w=a.at(j);
      }
      if(x)m=M;
      m=min(m,M);
      x=false;
    }
  }
  cout<<m<<endl;
}