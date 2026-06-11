#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second

#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e6+5, LG = 17, MOD = 1e9+7;
const int SQ = 390;
const long double EPS = 1e-7;
ll h, w;
int n;
set<ii> cnt[10];
set<ii> go;
int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> h >> w >> n;

  f(i,0,n){
    int x, y;
    cin >> x >> y;
    go.insert({x,y});
  }
  ll tot = (h-2)*(w-2);
  for(auto cell : go){
    int x = cell.F;
    int y = cell.S;
    f(prvx,0,3)
      f(prvy,0,3){
        int a = x - prvx;
        int b = x + (2 - prvx);
        int c = y - prvy;
        int d = y + (2 -prvy);
        if(a<=0||c<=0||b>h||d>w)continue;
        int sum = 0;
        f(i,a,b+1)
          f(j,c,d+1)
            sum+=go.count(ii(i,j));
        tot+=cnt[sum].size();
        cnt[sum].insert(ii(a,c));
        tot-=cnt[sum].size();
      }


  }

  cout<<tot<<endl;
  f(i,1,10)cout << cnt[i].size() << '\n';

  return 0;
}
