#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,M;
  cin>>N>>M;
  VL A(M),B(M),C(M);
  rep(i,M) cin>>A[i]>>B[i]>>C[i];
  VVL D(N,VL(N));
  rep(i,N) rep(j,N) if(i!=j) D[i][j]=1001001001001001001;
  rep(i,M){
    D[A[i]-1][B[i]-1]=C[i];
    D[B[i]-1][A[i]-1]=C[i];
  }
  rep(k,N) rep(i,N) rep(j,N) D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
  int ans=M;
  rep(k,M){
    int F=0;
    rep(i,N) rep(j,N) if(D[i][j]==D[i][A[k]-1]+D[B[k]-1][j]+C[k]) F=1;
    if(F) ans--;
  }
  cout<<ans<<endl;
}
