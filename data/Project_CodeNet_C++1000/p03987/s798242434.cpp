#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N;
  cin>>N;
  ll a[N];
  ll tmptmp;
  for(ll i=0;i<N;++i) {
    cin>>tmptmp;
    tmptmp--;
    a[tmptmp] = i;
  }
  set<ll> st;
  st.insert(-1);
  st.insert(N);
  auto tmp=st.begin(), tmp1=st.begin(), tmp2=st.begin();
  ll ans = 0;
  for(ll i=0;i<N;++i) {
    st.insert(a[i]);
    tmp = st.find(a[i]);
    tmp1 = st.find(a[i]);
    tmp1--;
    tmp2 = st.find(a[i]);
    tmp2++;
    ans += (i+1)*(*tmp-*tmp1)*(*tmp2-*tmp);
  }
  cout<<ans<<endl;
}

