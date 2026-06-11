#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N,L,T;
  cin>>N>>L>>T;
  std::vector<int> v(N),w(N),an(N);
  for(int i=0;i<N;i++)cin>>v[i]>>w[i];
  for(int i=0;i<N;i++){
    if(w[i]==1)an[i]=(v[i]+T)%L;
    else an[i]=(v[i]-(T%L)+L)%L;
  }
  int kk=0;
  int o=0;
  int po=an[0];
  sort(an.begin(),an.end());
  if(w[0]==1){
    for(int i=1;i<N;i++){
      if(w[i]==2){
        if(v[i]-v[0]<=T*2)kk++;
        kk+=max((T*2-(v[i]-v[0]))/L,o);
        kk%=N;
      }
    }
    for(o=N-1;o>=0;o--)if(an[o]==po)break;
    //now o is kk's position
    for(int i=0;i<N;i++){
      cout<<an[(o-kk+i+N)%N]<<endl;
    }
  }
  else{
    for(int i=1;i<N;i++){
      if(w[i]==1){
        if(v[0]+L-v[i]<=T*2)kk++;
        kk+=max((T*2-(v[0]+L-v[i]))/L,o);
        kk%=N;
      }
    }
    for(o=0;o<N;o++)if(an[o]==po)break;
    //now o is N-kk's position
    for(int i=0;i<N;i++){
      cout<<an[(o+i+kk)%N]<<endl;
    }
  }
}
