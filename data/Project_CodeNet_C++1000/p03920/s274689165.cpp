#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
  ll n;cin>>n;
  vector<ll>sum(n+1,0);
  for(int i=1;i <= n;i++)
  {
    sum[i]=sum[i-1]+i;
  }

  ll itr=lower_bound(all(sum),n)-sum.begin();

  for(int i=1;i <=itr ;i++)
  {
    if(i==sum[itr]-n)continue;
    else cout<<i<<endl;
  }
}