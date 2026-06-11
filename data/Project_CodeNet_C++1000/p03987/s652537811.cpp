#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,int> mp;
  rep(i,n) mp[a[i]]=i;
  set<int> st={-1,n};
  ll ans=0;
  for(ll i=1;i<=n;i++){
    auto itr=st.upper_bound(mp[i]);
    int r=*(itr);
    int l=*(prev(itr));
    ans+=i*(r-mp[i])*(mp[i]-l);
    st.insert(mp[i]);
  }
  cout << ans << endl;
}