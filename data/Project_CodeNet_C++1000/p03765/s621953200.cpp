#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int prefa[100005];
int prefb[100005];
void solve() {
  string s, t;
  cin >> s >> t;
  for(int i = 0; i < s.size(); i++) {
    prefa[i+1] = prefa[i];
    if(s[i] == 'A') prefa[i+1]++;
    else prefa[i+1] += 2;
  }
  for(int i = 0; i < t.size(); i++) {
    prefb[i+1] = prefb[i];
    if(t[i] == 'A') prefb[i+1]++;
    else prefb[i+1] += 2;
  }
  int q;
  cin >> q;
  while(q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((prefa[b] - prefa[a-1]) % 3 == (prefb[d] - prefb[c-1]) % 3) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
