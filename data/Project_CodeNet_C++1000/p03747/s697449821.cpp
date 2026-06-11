#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAX_N = 100000;
int n,l,t;
vector<int> lx,rx;
int pos[MAX_N];

int main()
{
  cin >> n >> l >> t;
  int x,w;
  for (int i = 0; i < n; i++) {
    cin >> x >> w;
    if (w == 1) {
      rx.pb(x);
    } else {
      lx.pb(x);
    }
  }

  i64 d = (t / l * (lx.size() - rx.size() + n)) % n;
  t = t % l;

  //printf("t=%d l=%d\n", t, l);
  i64 lc = 0;
  for (int v : lx) {
    if (v < t) lc++;
  }

  i64 rc = 0;
  for (int v : rx) {
    if (v >= l - t) rc++;
  }

  i64 first = (d + lc - rc + n) % n;

  vector<int> last_pos;
  for (int x : rx) {
    last_pos.pb((x+t)%l);
  }
  for (int x : lx) {
    last_pos.pb((x-t+l)%l);
  }

  sort(last_pos.begin(), last_pos.end());

  for (int i = 0; i < n; i++) {
    pos[(first+n)%n] = last_pos[i];
    first++;
  }

  for (int i = 0; i < n; i++) {
    cout << pos[i] << endl;
  }

  return 0;
}
