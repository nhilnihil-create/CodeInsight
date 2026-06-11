#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
#include <random>
#include <queue>
#include <deque>
#include <tuple>
#include <iomanip>
#include <iterator>
#include <functional>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin>>N;
  vector<ll>A(3*N);
  REP(i,3*N)cin>>A[i];

  ll now=0ll;
  priority_queue<ll, vector<ll>, greater<int>> left;
  priority_queue<ll> right;

  vector<ll> sum_left,sum_right;

  REP(i,N){
    left.push(A[i]);
    now+=A[i];
  }
  sum_left.push_back(now);

  FOR(i,N,2*N){
    now+=A[i];
    left.push(A[i]);
    now-=left.top();
    left.pop();
    sum_left.push_back(now);
  }

  reverse(ALL(A));
  now=0ll;

  REP(i,N){
    right.push(A[i]);
    now+=A[i];
  }
  sum_right.push_back(now);

  FOR(i,N,2*N){
    now+=A[i];
    right.push(A[i]);
    now-=right.top();
    right.pop();
    sum_right.push_back(now);
  }

  reverse(ALL(sum_right));

  ll ans=-INFLL;
  REP(i,N+1){
    ans=max(ans,sum_left[i]-sum_right[i]);
  }
  cout<<ans<<endl;
}
