#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin>>N>>T;
  std::vector<int> v(N+1);
  for(int i=0;i<N;i++)cin>>v[i];
  v[N]=0;
  int m=v[0];
  int k=0;
  int h=0;
  int i=0;
  while(v[i]>=v[i+1])i++;
  m=v[i];
  int M=v[i];
  for(i=i+1;i<N+1;i++){
    M=max(M,v[i]);
    if(m>v[i]){
      if(h==M-m)k++;
      if(h<M-m){
        k=1;
        h=M-m;
      }
      m=v[i];
      M=v[i];
    }
  }
  cout<<k<<endl;
}
