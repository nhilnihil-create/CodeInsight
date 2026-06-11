#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int N,M;
ll X[101010],K;
int A[62][101010], dy[101010];

int main(){
  cin>>N;
  rep(i,N) cin>>X[i];
  rep(i,N-1) A[0][i]=dy[i]=i;
  cin>>M>>K;
  rep(i,M){
    int x; cin>>x; x--;
    swap(A[0][x-1],A[0][x]);
  }
  rep(i,61){
    rep(j,N){
      A[i+1][j]=A[i][A[i][j]];
    }
  }
  
  rep(i,61){
    if(K&(1LL<<i)){
      rep(j,N) dy[j]=A[i][dy[j]];
    }
  }
  ll sum=X[0];
  rep(i,N){
    cout<<sum<<endl;
    sum+=X[dy[i]+1]-X[dy[i]];
  }
  return 0;
}
