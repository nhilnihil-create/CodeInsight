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

ll N, L;
vector<ll> x(100005, big);
ll nexthotel[20][100005];

void prepare() {
  ll index;
  for(ll i=0;i<N;++i) {
    index = upper_bound(x.begin(), x.end(), x[i]+L) - x.begin() - 1;
    nexthotel[0][i] = index;
  }
  for(ll i=1;i<20;++i) {
    for(ll j=0;j<N;++j) {
      nexthotel[i][j] = nexthotel[i-1][nexthotel[i-1][j]];
    }
  }
}

int main() {
  cin>>N;
  for(ll i=0;i<N;++i) cin>>x[i];
  cin>>L;
  prepare();
  /**
  for(ll i=0;i<20;++i) {
    for(ll j=0;j<N;++j) {
      cout<<nexthotel[i][j]<<" ";
    }
    cout<<endl;
  }
  **/
  ll Q;
  cin>>Q;
  ll A, B;
  vector<ll> ans(Q, 0);
  ll tmp;
  ll two;
  for(ll i=0;i<Q;++i) {
    cin>>A>>B;
    A--;
    B--;
    if(A>B) swap(A, B);
    while(A<B) {
      tmp = 0;
      two = 1;
      while(nexthotel[tmp+1][A]<B) {
        two *= 2;
        tmp++;
      }
      A = nexthotel[tmp][A];
      ans[i] += two;
    }
  }
  for(ll i=0;i<Q;++i) cout<<ans[i]<<endl;
}

