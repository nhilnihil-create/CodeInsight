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
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int p[100010];
int main() {
   int N; cin >> N;
   int q = 0;
   int cnt = 0;
   rep1(i, N) {
      cin >> p[i];
      if (p[i] == i) {
         q++;
      } else if (q > 0) {
         cnt += (q+1)/2;
         q=0;
      }
   }
   cnt += (q+1)/2;
   cout << cnt << endl;
}