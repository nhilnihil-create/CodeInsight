#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)
#define INF (1001001001)
#define EPS (1e-15)

#define pr(x) do{cerr << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cerr << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x,n) rep(__i,n) pri(x,__i);
#define prar(x,b,e) repr(__i,b,e) pri(x,__i);

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;

ll MOD = 1000000007;

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

int H, W, d;
int c(int y, int x) {
	return y * H + x;
}
bool isRanged(int y, int x) {
	return y >= 0 && y < H && x >= 0 && x < W;
}
int main() {
	H = in();
	W = in();
	d = in();
	
	if (d % 2 == 1) {
		rep(y, H) {
			rep(x, W) {
				cout << ((y + x) % 2 ? "R" : "B");
			}
			cout << endl;
		}
		return 0;
	}
	
	vector<vint> area(H, vint(W, 0));
	int N = max(H, W) + 3;
	rep(s, N) {
		repr(t, -N, N) {
			int y = s * d / 2 - t * (d / 2 - 1);
			int x = s * d / 2 + t * (d / 2 + 1);
			if (y + d / 2 <= 0) break;
			if (x >= W) break;
			if (x + d < 0) continue;
			repr(k, - d / 2 + 1, d / 2 - 1) repr(i, abs(k), d - abs(k)) {
				if (! isRanged(y + k, x + i)) continue;
				area[y + k][x + i] = (s & 1) * 2 + (t & 1);
			}
		}
	}
	
	rep(y, H) {
		rep(x, W) cout << ("RGBY"[area[y][x]]);
		cout << endl;
	}
	
	return 0;
}
