#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

ll pos[2][200005];

int main() {
  int N;
  cin>>N;
  vector<int> arr(N);
  int a;
  for(int i=0;i<N;++i){
    cin>>a;
    a--;
    arr[a] = i;
  }
  set<int> st;
  auto l=st.begin(), m=st.begin(), r=st.begin();
  for(int i=0;i<N;++i){
    st.insert(arr[i]);
    m = st.find(arr[i]);
    if(m!=st.begin()){
      l = prev(m);
      pos[0][i] = *l + 1;
    }
    if(next(m)==st.end()){
      pos[1][i] = N;
    }
    else{
      r = next(m);
      pos[1][i] = *r;
    }
  }
  ll ans = 0;
  for(ll i=0;i<N;++i){
    ans += (i+1)*(arr[i]-pos[0][i]+1)*(pos[1][i]-arr[i]);
  }
  cout<<ans<<endl;
}
