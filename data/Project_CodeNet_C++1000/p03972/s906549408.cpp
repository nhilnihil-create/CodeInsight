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

void solve() {
  int w, h;
  vector<ll> horiz, vert;
  cin >> w >> h;
  horiz.resize(w);
  for(int i = 0; i < w; i++) cin >> horiz[i];
  sort(horiz.begin(), horiz.end());
  vert.resize(h);
  for(int i = 0; i < h; i++) cin >> vert[i];
  sort(vert.begin(), vert.end());
  ll ret = 0;
  int hh = 0;
  int ww = 0;
  while(ww < horiz.size() || hh < vert.size()) {
    if(ww < horiz.size() && (hh == vert.size() || horiz[ww] < vert[hh])) {
      ret += (vert.size()+1-hh) * horiz[ww++];
    }
    else {
      ret += (horiz.size()+1-ww) * vert[hh++];
    }
  }
  cout << ret << endl;
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
