#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef pair<string, string> S;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int H, W, h, w;

void solve() {
    int a[H][W];
    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return;
    } else if (H % h != 0) {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                a[j][i] = ((j+1)%h==0 ? -100000*(h-1)-1  : 100000);
            }
        }
    } else {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                a[i][j] = ((j+1)%w==0 ? -100000*(w-1)-1 : 100000);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << a[i][j];
            if (j < W-1)
                cout << " ";
        }
        cout << endl;
    }
}

void input() {
    cin >> H >> W >> h >> w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
