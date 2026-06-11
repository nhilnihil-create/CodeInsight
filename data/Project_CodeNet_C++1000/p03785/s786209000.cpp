#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
typedef pair<ll, ll> P;
int main() {
    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll>t(n);
    rep(i, 0, n) {
        ll tmp = 0;
        cin >> tmp;
        t[i] = tmp;
    }
    sort(t.begin(), t.end());
    int bus = 0;
    for (int i = 0; i < n;) {
      ++bus;
      int starti = i;
      while (i < n && t.at(i) - t.at(starti) <= k && i - starti < c) ++i;
    }
    cout << bus << endl;
   return 0;
}
