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

int main() {
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll ans;
  ll tmpans;
  tmpans = 0;
  ll sum = A[0];
  for(int i=0;i<N-1;++i) {
    if(i%2==0 && sum<=0) {
      tmpans += 1-sum;
      sum = 1;
    }
    if(i%2==1 && sum>=0) {
      tmpans += 1+sum;
      sum = -1;
    }
    sum += A[i+1];
  }
  if(N%2==0 && sum>=0) {
    tmpans += 1+sum;
  }
  if(N%2==1 && sum<=0) {
    tmpans += 1-sum;
  }
  ans = tmpans;
  sum = A[0];
  tmpans = 0;
  for(int i=0;i<N-1;++i) {
    if(i%2==0 && sum>=0) {
      tmpans += 1+sum;
      sum = -1;
    }
    if(i%2==1 && sum<=0) {
      tmpans += 1-sum;
      sum = 1;
    }
    sum += A[i+1];
  }
  if(N%2==0 && sum<=0) {
    tmpans += 1-sum;
  }
  if(N%2==1 && sum>=0) {
    tmpans += 1+sum;
  }
  ans = min(ans, tmpans);
  cout<<ans<<endl;
}

