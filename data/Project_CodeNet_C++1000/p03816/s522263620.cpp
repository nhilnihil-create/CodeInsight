#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,v;
  cin >> n;
  ll a[n];
  set<ll> st;
  for(int i=0;i<n;i++){
    cin >> a[i];
    st.insert(a[i]);
  }
  v = st.size();
  if(v%2==0) v--;
  cout <<v <<endl;
}
