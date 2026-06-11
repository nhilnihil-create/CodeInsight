#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin >> n;
  vector<ll> a(n),b(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    a[i]--;
    b[a[i]]=i;
  }
  set<ll> st,st2;
  ll ans=0;
  st.insert(-1);
  st.insert(n);
  st2.insert(1);
  st2.insert(-n);
  for(int i=0;i<n;i++){
    auto itr=st.upper_bound(b[i]);
    auto itr2=st2.upper_bound(-b[i]);
    ans+=(*itr-b[i])*(b[i]+*itr2)*(i+1);
    st.insert(b[i]);
    st2.insert(-b[i]);
  }
  cout << ans << endl;
}