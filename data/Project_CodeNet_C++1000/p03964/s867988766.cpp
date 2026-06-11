#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100

int main(){
  int N;
  cin>>N;
  vector<ll> T(N),A(N);
  ll voteT=0,voteA=0;
  for(int i=0;i<N;i++){
    cin>>T.at(i)>>A.at(i);
  }
  voteT=T.at(0);
  voteA=A.at(0);
  for(int i=1;i<N;i++){
    ll x=max((voteT-1)/T.at(i)+1,(voteA-1)/A.at(i)+1);
    voteT=T.at(i)*x;
    voteA=A.at(i)*x;
  }
  cout<<voteT+voteA<<endl;
}
