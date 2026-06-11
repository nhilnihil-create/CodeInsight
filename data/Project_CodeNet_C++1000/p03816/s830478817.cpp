// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,ans,a;
  set<ll> st;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a;
    st.insert(a);
  }
  ans = st.size();
  if(ans%2==0) ans--;
  cout << ans << endl;
}
