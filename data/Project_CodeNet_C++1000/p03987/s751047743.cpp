#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  vector<P> vec;
  ll ans=0;
  ll n;
  cin>>n;
  vec.push_back(P(0,0));
  set<ll> st,st_;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    vec.push_back(P(a,i));
  }
  vec.push_back(P(n+1,n+1));
  sort(vec.begin(),vec.end());
  st.insert(n+1);
  st_.insert(0);
  for(int i=1;i<=n;i++){
    ll idx=vec[i].second;
    ll k=*(st.upper_bound(idx));
    ll j=*(st_.upper_bound(-idx));
    j*=-1;
    ans+=i*(idx-j)*(k-idx);
  //  cout<<vec[i].first<<" "<<vec[i].second<<" "<<i-j<<" "<<k-i<<" "<<i*(i-j)*(k-i)<<endl;
    st.insert(idx);
    st_.insert(-idx);
  }

  cout<<ans<<endl;
}
