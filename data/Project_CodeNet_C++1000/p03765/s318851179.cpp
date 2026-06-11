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
  string S,T;
  cin>>S>>T;
  int Q;
  cin>>Q;
  VI A(Q),B(Q),C(Q),D(Q);
  rep(i,Q) cin>>A[i]>>B[i]>>C[i]>>D[i];
  VI X(S.size()+1),Y(T.size()+1);
  rep(i,S.size()) X[i+1]=X[i]+1+(S[i]=='B');
  rep(i,T.size()) Y[i+1]=Y[i]+1+(T[i]=='B');
  rep(i,Q) cout<<(((X[B[i]]-X[A[i]-1])%3==(Y[D[i]]-Y[C[i]-1])%3)?"YES":"NO")<<endl;
}