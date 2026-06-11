#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin>>N>>A>>B;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  int X=0;
  for(int i=1;i<A;i++){
    if(p[i]!=p[i-1]){
      X=i;
    }
  }
  int64_t Z=0,ans=1;
  for(int i=0;i<A;i++){
    Z+=p[i];
  }
  double potato=Z;
  potato/=A;
  cout<<fixed<<setprecision(20);
  cout<<potato<<endl;
  if(X){
    int S=A;
    while(S<N){
      if(p[S]!=p[S-1]){
        break;
      }
      S++;
    }
    S-=A;
    for(int i=0;i<S;i++){
      ans*=(A-X+S-i);
      ans/=(i+1);
    }
  }
  else{
    int S=A;
    while(S<N){
      if(p[S]!=p[S-1]){
        break;
      }
      S++;
    }
    ans--;
    for(int i=A;i<=min(B,S);i++){
      int64_t L=1;
      for(int j=0;j<i;j++){
        L*=(S-j);
        L/=(j+1);
      }
      ans+=L;
    }
  }
  cout<<ans<<endl;
}