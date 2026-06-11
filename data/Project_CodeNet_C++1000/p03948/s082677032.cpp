#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define US unordered_set
#define ALL(a) (a).begin(),(a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> Graph;

int main(){
  int N,T; cin>>N>>T;
  vi A(N); REP(i,N) cin>>A[i];
  vi B(N);
  B[N-1]=A[N-1];
  for(ll i=N-2;i>=0;i--) B[i]=max(A[i],B[i+1]);
  vi C(N);
  REP(i,N) C[i]=B[i]-A[i];
  ll ma=C[0]; for(ll i:C) ma=max(ma,i);
  ll cnt=0;
  for(ll i:C) if(i==ma) cnt++;
  cout<<cnt<<endl;
}
