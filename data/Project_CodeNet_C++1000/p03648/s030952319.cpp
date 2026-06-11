#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  ll K; cin>>K;
  ll A[50];
  rep(i,50) A[i]=49-(K%50)+K/50;
  rep(i,K%50) A[i]+=50;
  cout<<50<<endl;
  rep(i,49) cout<<A[i]<<" ";
  cout<<A[49]<<endl;
  return 0;
}
