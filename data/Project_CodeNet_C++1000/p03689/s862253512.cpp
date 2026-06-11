#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
ll inf = llmax / 2;
double eps = 1e-11;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if (W % w == 0 && H % h == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int low = -1e9;
    int high = (-low - 1) / (h * w - 1);
    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (i % h == 0 && j % w == 0) {
                cout << low;
            } else {
                cout << high;
            }
            if (j != W) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
