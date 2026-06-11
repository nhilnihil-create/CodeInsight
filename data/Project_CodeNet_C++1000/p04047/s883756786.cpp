#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define per(i,j,n) for(int i=(int)(j);(int)(n)<=i;i--)
#define int long long
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define endl "\n"
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<vi>
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=(1ll<<62)-1;
signed main(){
  ll N; cin>>N;
  vi A(2*N);
  rep(i,0,2*N) cin>>A[i];
  sort(ALL(A));
  ll ans=0;
  rep(i,0,N) ans+=A[i*2];
  cout<<ans<<endl;
}