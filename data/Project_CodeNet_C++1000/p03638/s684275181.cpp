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
  int H,W,N;cin>>H>>W>>N;
  vector<int> as(N);
  REP(i,N) cin>>as[i];

  int mas[H][W];
  int cur = 0;
  int tmp = 0;
  // 一筆書きで塗っていく
  REP(h,H) {
    if (h%2==1) {
      for (int w=W-1;w>=0;w--) {
        if (as[cur]==tmp) {
          cur++;
          tmp = 0;
        }
        mas[h][w] = cur+1;
        tmp++;
      }
    } else {
      REP(w,W) {
        if (as[cur]==tmp) {
          cur++;
          tmp = 0;
        }
        mas[h][w] = cur+1;
        tmp++;
      }
    }
  }
  REP(h,H) {
    DUMP(mas[h]);
  }

  return 0;
}