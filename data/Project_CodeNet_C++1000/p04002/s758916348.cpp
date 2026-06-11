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
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bs2int(bs) (int)((bs).to_ulong())
#define DEBUG(X) cerr<<"  "<<#X<<" = "<<X<<endl
#define DUMP(A, n) for (auto x=begin(A); x!=begin(A)+n;x++){cout <<*x<< ' ';} cout<<endl;
#define DUMPP(A, n, m) for (auto x=begin(A); x != begin(A)+n;x++) {for (auto y=begin(*x); y != begin(*x)+m;)cout <<*y++<< ' '; cout<<endl;};
#define DUMPM(M) for (auto itr=mp.begin(); itr!=mp.end(); itr++) {cout<<itr->first<<" -> "<<itr->second<<endl;}
#define FOR(i,x,y) for(int i=(x);i<(int)(y);i++)
#define FORP(i,x,y) for(int i=(x);i<=(int)(y);i++)
#define REP(i,y) for(int i=0;i<(int)(y);i++)
#define REPP(i,y) for(int i=1;i<=(int)(y);i++)
#define REPB(i,n) for(int i=(int)(n)-1;i>=0;i--)

using P = pair<int, int>;

int h,w,n;
map<P, int> mp;
int dx[9] = {1, 0, -1,  0, 1, -1,  1, -1, 0};
int dy[9] = {0, 1,  0, -1, 1, -1, -1,  1, 0};
int j[10];
ll sum;

bool check(int x, int y) {
  return !(x<=1||x>=w||y<=1||y>=h);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>h>>w>>n;
  REP(i,n) {
    int y,x; cin>>y>>x;
    REP(i,9) {
      P np = {x+dx[i], y+dy[i]};
      if (!check(np.first, np.second)) continue;

      int pr = mp[np];
      if (pr) j[pr]--;
      if (pr==0) sum++;

      ++j[++mp[np]];
    }
  }
  cout << ((h-2)*1LL*(w-2))-sum << endl;
  FOR(i,1,10) {
    cout << j[i] << endl;
  }
}
