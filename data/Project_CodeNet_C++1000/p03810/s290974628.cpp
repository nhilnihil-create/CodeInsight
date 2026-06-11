#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
  	scanf("%d", &a[i]);
  }
  return true;
}

int rec() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum ^= ((a[i] + 1) & 1);
	}
	if (sum & 1) {
		return true;
	}
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1) {
			if (pos != -1) {
				return false;
			}
			pos = i;
		}
	}
	if (a[pos] == 1) {
		return false;
	}
	a[pos]--;
	int g = 0;
	for (int i = 0; i < n; i++) {
		g = gcd(g, a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] /= g;
	}
	if (!rec()) {
		return true;
	}
	return false;
}

void solve() {
	int res = rec();
	if (res) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}