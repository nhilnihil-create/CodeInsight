#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1LL<<60
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int main() {
  ll h, w, n;
  cin >> h >> w >> n;
  ll p[10] = { };
  p[0] = (h-2) * (w-2);
  set<P> s;
  REP(i, n){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int f[3][3] = { };
    FOR(j, a-2, a+3){
      FOR(k, b-2, b+3){
        if(s.find({j, k}) != s.end()){
           FOR(l, j-2, j+1){
             FOR(m, k-2, k+1){
               if(0 <= l && l < h && 0 <= m && m < w && -2 <= l-a && l-a <= 0 && -2 <= m-b && m-b <= 0){
                 f[l-a+2][m-b+2]++;
               }
            }
          }
        }
      }
    }
    REP(j, 3){
      REP(k, 3){
        if(0 <= a-2+j && a+j < h && 0 <= b-2+k && b+k < w){
          p[f[j][k]]--;
          p[f[j][k]+1]++;
        }
      }
    }
    s.insert({a, b});
  }
  REP(i, 10){
    cout << p[i] << endl;
  }
}