#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  int x[N];
  int kyori[N];
  int ans=0;
  for(int i=0;i<N;i++){
    cin>>x[i];
    kyori[i]=min(x[i],abs(K-x[i]));
    int m=kyori[i]*2;
    ans+=m;
  }
  cout<<ans<<endl;
}