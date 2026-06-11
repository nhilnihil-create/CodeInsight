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
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
map<ll,pair<ll,ll>>cnt;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
    cnt[A[i]].F++;
    if(cnt[A[i]].F==1)cnt[A[i]].S=i;
  }
  vector<pair<ll,pair<ll,ll>>>pll;
  for(auto a:cnt){
    pll.pb(mp(a.F,mp(a.S.F,a.S.S)));
  }
  sort(ALL(pll),greater<pair<ll,pair<ll,ll>>>());
  vi ans(n+10);
  for(int i=0;i<pll.size()-1;i++){
    ll sa=pll[i].F-pll[i+1].F;
    ans[pll[i].S.S]+=sa*pll[i].S.F;
    pll[i+1].S.S=min(pll[i+1].S.S,pll[i].S.S);
    pll[i+1].S.F+=pll[i].S.F;
    // cout<<ans[pll[i].S.S]<<endl;
  }
  //cout<<pll.back().F<<endl;
  ans[0]+=pll.back().S.F*pll.back().F;
  for(int i=0;i<n;i++)
    cout<<ans[i]<<endl;
  return 0;
}
