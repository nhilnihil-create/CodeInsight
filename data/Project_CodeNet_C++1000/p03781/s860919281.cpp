#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<queue>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

int main() {
  ll x;
  cin >> x;
  ll sum = 0;
  int cnt = 0;
  for(ll i=1;sum<x;i++) {
    sum += i;
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}