#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin>>N;
  vector<int> T(N);
  rep(i,N) cin>>T[i];
  cin>>M;
  vector<int> P(M);
  vector<int> X(M);
  rep(i,M) cin>>P[i]>>X[i];
  int sum=0;
  int E;
  rep(i,M){
    sum=0;
    E=T[P[i]-1];
    T[P[i]-1]=X[i];
    rep(j,N) sum+=T[j];
    cout<<sum<<endl;
    T[P[i]-1]=E;
  }
}