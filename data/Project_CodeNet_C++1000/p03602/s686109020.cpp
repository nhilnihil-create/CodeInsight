#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <cmath>
using namespace std;
typedef long long ll;
//typedef pair<ll, ll> P;

#define rep(i, m) for(ll i=0;i<(m);i++)
#define rep1(i, m) for(ll i=1;i<=(m);i++)
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

ll N;
ll A[310][310];
ll d[310][310];
const ll INF = 10000000039LL;
int main() {
   cin >> N;
   rep(i, N) {
      rep(j, N) {
         cin >> A[i][j];
         d[i][j] = INF;
         d[i][j] = A[i][j];
      }
   }
   rep(i, N) {
      rep(j, N) {
         rep(k, N) {
            d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
         }
      }
   }
   bool isrealizible = true;
   rep(i, N) {
      rep(j, N) {
         isrealizible &= (d[i][j] >= A[i][j]);
      }
   }
   if (!isrealizible) {
      cout << -1 << endl;
      return 0;
   }
   ll ans = 0;
   rep(i, N) {
      for (int j=i+1;j<N;j++) {
         bool canRemove = false;
         rep(k, N) {
            if (i == k || j == k) continue;
            if (d[i][j] == d[i][k] + d[k][j]) {
               canRemove = true; break;
            }
         }
         if (!canRemove) ans += A[i][j];
      }
   }
   cout << ans << endl;
}