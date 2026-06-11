#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N,M,R;
  cin>>N>>M>>R;
  VL S(R);
  rep(i,R) cin>>S[i];
  VL A(M),B(M),C(M);
  rep(i,M) cin>>A[i]>>B[i]>>C[i];
  VVL X(N,VL(N));
  rep(i,N) rep(j,N) if(i!=j) X[i][j]=(1<<29);
  rep(i,M){
    X[A[i]-1][B[i]-1]=C[i];
    X[B[i]-1][A[i]-1]=C[i];
  }
  rep(k,N) rep(i,N) rep(j,N) X[i][j]=min(X[i][j],X[i][k]+X[k][j]);
  ll ans=(1<<29);
  sort(all(S));
  do{
    ll sum=0;
    rep(i,R-1) sum+=X[S[i]-1][S[i+1]-1];
    ans=min(ans,sum);
  }while(next_permutation(all(S)));
  cout<<ans<<endl;
}