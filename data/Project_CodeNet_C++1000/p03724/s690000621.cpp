#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> imos(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    imos[a]++;
    imos[b]++;
  }
  int cur = 0;
  bool ans = true;
  rep(i, n) {
    if (cur % 2) ans = false;
    cur += imos[i];
  }
  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;

}