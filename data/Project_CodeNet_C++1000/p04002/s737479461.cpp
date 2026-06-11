#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,n;
  cin>>h>>w>>n;
  vector<ll> ans(10,0);
  ans[0]=(h-2)*(w-2);
  map<P,ll> cnt;
  rep(i,n){
    int a,b;
    cin>>a>>b;
    rep(j,3)rep(k,3){
      if(1<=a-j && a+2-j<=h && 1<=b-k && b+2-k<=w){
        cnt[P(a-j,b-k)]++;
      }
    }
  }
  for(auto itr:cnt){
    ans[itr.se]++;
    ans[0]--;
  }
  cout_vec(ans);
}