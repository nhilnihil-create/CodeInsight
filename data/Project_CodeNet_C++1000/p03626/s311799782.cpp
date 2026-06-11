#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define ALLTRUE(xs) all_of(ALL(xs),[](bool x){return x;})
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define ANYTRUE(xs) any_of(ALL(xs),[](bool x){return x;})
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define OR(x,y,z) set_union((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  const int MOD = 1000000007;
  int N;cin>>N;
  string S1,S2;cin>>S1>>S2;

  // 0~N-1まで見ていって、上と下が同じならたてドミノ、違うなら横ドミノで判定
  int cur = 0;
  ll ans = 0;
  bool prev_vertical;
  if (S1[0]==S2[0]) {
    prev_vertical = true;
    ans += 3;
    cur++;
  } else {
    prev_vertical = false;
    ans += 6;
    cur+=2;
  }
  while (cur<N) {
    if (S1[cur]==S2[cur]) {
      if (prev_vertical) {
        ans = ans*2%MOD;
      } else {
        // パターン増えない
      }
      prev_vertical = true;
      cur++;
    } else {
      if (prev_vertical) {
        ans = ans*2%MOD;
      } else {
        ans = ans*3%MOD;
      }
      prev_vertical = false;
      cur += 2;
    }
  }
  OUT(ans);

  return 0;
}