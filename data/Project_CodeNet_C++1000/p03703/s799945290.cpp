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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll bit[200005];

void add(ll x) {
  while(x<200005) {
    bit[x]++;
    x += x&-x;
  }
}

ll sum(ll x) {
  ll ans = 0;
  while(x>0) {
    ans += bit[x];
    x -= x&-x;
  }
  return ans;
}

int main() {
  ll N, K;
  cin>>N>>K;
  ll A[N+1];
  for(int i=0;i<N;++i) {
    cin>>A[i+1];
    A[i+1] -= K;
  }
  A[0] = 0;
  for(int i=1;i<=N;++i) A[i] += A[i-1];
  vector<ll> arr;
  map<ll, int> amap;
  for(int i=0;i<=N;++i) {
    if(amap[A[i]]==0) arr.push_back(A[i]);
    amap[A[i]]++;
  }
  sort(arr.begin(), arr.end());
  map<ll, int> bmap;
  for(int i=0;i<arr.size();++i) {
    bmap[arr[i]] = i+1;
  }
  add(bmap[0]);
  ll ans = 0;
  for(int i=1;i<=N;++i) {
    ans += sum(bmap[A[i]]);
    add(bmap[A[i]]);
  }
  cout<<ans<<endl;
}

