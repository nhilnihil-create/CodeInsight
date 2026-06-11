// darksta5's template v2.0

#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PI acos(-1)
#define eps 1e-9
#define MOD 1000000007
using namespace std;

int h, w, n;
LL ans[10];
set<pair<int, int> > st;

bool isValid(int x, int y) {
  return (x >= 0) && (x + 2 < h) && (y >= 0) && (y + 2 < w);
}

int countDot(int x, int y) {
  int ret = 0;
  FORS(i, x, x + 2) {
    FORS(j, y, y + 2) {
      if (st.find(mp(i, j)) != st.end()) {
        ret++;
      }
    }
  }

  return ret;
}

void draw(int x, int y) {
  FORS(i, x - 2, x) {
    FORS(j, y - 2, y) {
      if (isValid(i, j)) {
        int cnt = countDot(i, j);
        ans[cnt]--;
        ans[cnt+1]++;
      }
    }
  }

  st.ins(mp(x, y));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> n;
  
  RES(ans, 0LL);
  ans[0] = (LL)(h - 2) * (LL)(w - 2);
  st.clear();

  FORN(i, n) {
    int a, b;
    cin >> a >> b;

    draw(a - 1, b - 1);
  }

  FORN(i, 10) {
    cout << ans[i] << endl;
  }
}