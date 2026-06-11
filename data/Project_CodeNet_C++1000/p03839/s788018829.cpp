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
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    vector<ll> s1(n+1,0),s2(n+1,0);
    FOR(i,1,n+1){
      cin>>a[i];
      s1[i]=s1[i-1]+a[i];
      if(a[i]>0) s2[i]=s2[i-1]+a[i];
      else s2[i]=s2[i-1];
    }
    ll ans=0;
    //cout_vec(s2);
    FOR(i,1,n+1){
      if(i+k-1>n) break;
      //cout<<i<<' '<<s1[i+k-1]-s1[i-1]<<' '<<s2[i-1]<<' '<<s2[n]-s2[i+k-1]<<endl;
      ans=max(ans,s1[i+k-1]-s1[i-1]+s2[i-1]+s2[n]-s2[i+k-1]);
      ans=max(ans,s2[i-1]+s2[n]-s2[i+k-1]);
    }
    cout<<ans<<endl;
}