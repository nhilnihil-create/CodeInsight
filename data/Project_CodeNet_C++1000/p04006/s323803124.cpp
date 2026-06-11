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
  ll N, x;
  cin>>N>>x;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll ans = big;
  ll tmpans;
  for(int k=0;k<N;++k) {
    multiset<ll> st;
    for(int i=0;i<k;++i) {
      st.insert(A[N-1-i]);
    }
    tmpans = k*x;
    for(int i=0;i<N;++i) {
      st.insert(A[i]);
      tmpans += *st.begin();
      if(i>=k) st.erase(st.find(A[i-k]));
      else st.erase(st.find(A[N-(k-i)]));
    }
    ans = min(ans, tmpans);
  }
  cout<<ans<<endl;
}

