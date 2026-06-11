#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 998244353;

int main() {
  ll N,L,T;cin >> N >> L >> T;
  vll X(N);
  vll Y(N);
  vint W(N);
  map<ll,int> mp;
  repeat(i,N){
    cin >> X[i] >> W[i];
    W[i] = 3-2*W[i];
    Y[i] = (X[i]+W[i]*(T%L)+L)%L;
    mp[Y[i]]++;
  }
  ll j=0;
  repeat(i,N){
    if(mp[Y[i]]==1){
      j=i;
      break;
    }
  }
  ll y0=Y[j];
  ll j0=j;
  for(int i=0;i<N;i++){
    if(W[j0]==W[i])continue;
    ll l = (L+W[j0]*(X[i]-X[j0]))%L;
    debug(l);
    if(2*T<l)continue;
    j = (j+W[j0]+N)%N;
    j = (j+W[j0]*(((2*T-l)/L)%N)+N)%N;
  }
  debug(j);
  vll ans(N);
  sort(Y.begin(),Y.end());
  int idx = lower_bound(Y.begin(),Y.end(),y0)-Y.begin();
  repeat(i,N){
    ans[(i+j)%N] = Y[(i+idx)%N];
  }
  repeat(i,N){
    cout << ans[i] << endl;
  }
  return 0;
}
