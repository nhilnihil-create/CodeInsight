#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N;cin>>N;
  vector<ll> A(N);rep(i,N)cin>>A[i];
  sort(A.begin(),A.end(),greater<ll>());
  ll i=0,k=0,edge[2];
  edge[0]=0;edge[1]=0;
  while(k<2&&i<N-1){
    if(A[i]==A[i+1]){
      edge[k]=A[i];
      ++k;
      ++i;
    }
    ++i;
  }
  cout << edge[0]*edge[1] << endl;
}