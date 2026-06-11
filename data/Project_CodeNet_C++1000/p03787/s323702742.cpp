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

ll N,M;
VI U(200200),V(200200);
VVI X(100100,VI(0));
VI D(100100,-1);

int solve(int P){
  if(D[P]==-1) D[P]=0;
  if(X[P].size()==0) return 0;
  queue<int> Q;
  Q.push(P);
  int F=1;
  while(!Q.empty()){
    int tmp=Q.front();
    Q.pop();
    rep(i,X[tmp].size()){
      if(D[X[tmp][i]]==-1){
        D[X[tmp][i]]=(D[tmp]+1)%2;
        Q.push(X[tmp][i]);
      }else if(D[X[tmp][i]]==D[tmp]) F=0;
    }
  }
  if(F) return 1;
  return 2;
}

int main(){
  cin>>N>>M;
  rep(i,M) cin>>U[i]>>V[i];
  VL A(3);
  rep(i,M){
    X[U[i]-1].pb(V[i]-1);
    X[V[i]-1].pb(U[i]-1);
  }
  rep(i,N) if(D[i]==-1) A[solve(i)]++;
  cout<<A[0]*A[0]+A[0]*(N-A[0])*2+A[1]*A[1]*2+A[1]*A[2]*2+A[2]*A[2]<<endl;
}