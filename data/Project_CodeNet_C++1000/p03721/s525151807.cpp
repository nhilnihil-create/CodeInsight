#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,e) for(int i=(s);(i)<(int)(e);++(i))
#define REP(i,e) FOR(i,0,e)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define ppb(x) pop_back(x)
#define mp make_pair
#define mt make_tuple
#define t0(t) get<0>((t))
#define t1(t) get<1>((t))
#define t2(t) get<2>((t))

typedef long long ll;
int n;
ll k;

int main() {
  fscanf(stdin, "%d%lld ", &n, &k);
  vector<pair<ll, ll>> ab(n);
  REP(i,n) {
    ll a, b;
    fscanf(stdin, "%lld%lld ", &a, &b);
    ab[i] = mp(a, b);
  }
  sort(ab.begin(), ab.end());
  ll cnt = 0;
  REP(i,n) {
    ll a = ab[i].first, b = ab[i].second;
    cnt += b;
    if (cnt >= k) {
      fprintf(stdout, "%lld\n", a);
      return 0;
    } 
  }
  return 0;
}
