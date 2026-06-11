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

struct edge { int to,cost; };

int main() {
  int N;cin>>N;
  map<int,int> mp;
  REP(i,N) {
    int a;cin>>a;
    mp[a]++;
  }
  int tmp = 0;
  for (auto m:mp) {
    if (m.second > 1) {
      tmp += m.second-1;
    }
  }
  int action_cnt = (tmp+1)/2;
  OUT(N-action_cnt*2);

  return 0;
}