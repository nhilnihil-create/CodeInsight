#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<"!"<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll rui[333333];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
    rui[i+1]+=rui[i]+A[i];
  }
  ll ans=llINF;
  for(int i=1;i<n;i++){
    ans=min(ans,abs(rui[i]-(rui[n]-rui[i])));
  }
  cout<<ans<<endl;
  return 0;
}
