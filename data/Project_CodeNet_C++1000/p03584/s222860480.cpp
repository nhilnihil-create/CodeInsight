#include <map>
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
using ld = long double;

template<class T> bool chmin(T &a, T b) { return a>b?(a=b,true):false; }
template<class T> bool chmax(T &a, T b) { return a<b?(a=b,true):false; }
#define FOR(i,x,y) for(int i=(x);i<(int)(y);i++)
#define REP(i,y) for(int i=0;i<(int)(y);i++)
#define repp(i,y) for(int i=1;i<=(int)(y);i++)
#define REPB(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bs2int(bs) ((bs).to_ullong())
#define debug(X) cerr<<" "<<#X<<" = "<<X<<endl;


template<class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << " ";
    os << *it;
  }
  return os;
}

// 要整形
// 1. rightmostはいらない
// 2. bitsetを使わないように書き換える

ll n,k;
ll a[100100], b[100100];

int main() {
  cin>>n>>k;
  vector<int> v;
  v.push_back(k);
  for(int i=0; (k>>i)>0; i++) {
    int cand = k;
    REP(j,i) cand |= (1<<j);
    if ((cand>>i) & 1) cand -= (1<<i);

    if (cand < k) v.push_back(cand);
  }
  REP(i,n) {
    cin>>a[i]>>b[i];
  }
  ll mxans = 0;
  for (int k : v) {
    ll ans = 0;
    REP(i,n) {
      if (k==(k | a[i])) ans+=b[i];
    }
    chmax(mxans, ans);
  }
  cout << mxans << endl;
}
