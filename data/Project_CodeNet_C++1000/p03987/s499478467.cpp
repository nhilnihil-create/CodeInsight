#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){ cin >> a[i]; a[i]--;}
  vector<int> idx(n);
  rep(i,n){ idx[a[i]] = i; }

  set<int> st;
  ll ans = 0;
  for(int x=0; x<n; x++){
    int i = idx[x];
    ll c = 0;
    st.insert(i);
    int l = 0;
    int r = n-1;
    auto it = st.find(i);
    if(it!=st.begin()){
      it--;
      l = *it;
      l++;
    }
    it = st.find(i);
    it++;
    if(it!=st.end()){
      r = *it;
      r--;
    }
    c = (ll)(i-l+1)*(r-i+1);
    ans += c*(x+1);
  }

  cout << ans << endl;
  return 0;
}
