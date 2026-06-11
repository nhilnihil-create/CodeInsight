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
template<class T> bool chmin(T &a, T b) { return a>b?(a=b,true):false; }
template<class T> bool chmax(T &a, T b) { return a<b?(a=b,true):false; }
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bs2int(bs) (int)((bs).to_ulong())
#define FOR(i,x,y) for(int i=(x);i<(int)(y);i++)
#define FORP(i,x,y) for(int i=(x);i<=(int)(y);i++)
#define REP(i,y) for(int i=0;i<(int)(y);i++)
#define REPP(i,y) for(int i=1;i<=(int)(y);i++)
#define REPB(i,n) for(int i=(int)(n)-1;i>=0;i--)

int n;
int p[100010];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  int cnt=0;
  FOR(i,1,n+1)
  {
    cin>>p[i-1];
    if (p[i-1]==i)cnt++;
  }
  int cntpair=0;
  REP(i,n-1)
    if (p[i]==i+1 && p[i+1]==i+2) cntpair++,i++;
  cout << cnt - cntpair << endl;
}
