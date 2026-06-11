#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 555;

int main() {
    ios::sync_with_stdio(false);

    int sx, sy;
    int d;
    cin >> sx >> sy >> d;

    if (d % 2 == 1) {
        for (int i = 0; i < sx; ++i) {
            for (int j = 0; j < sy; ++j)
                cout << "RGBY"[(i%2)*2 + (j%2)];
            cout << "\n";
        }
    } else {
        int r = d / 2;
        for (int x = 0; x < sx; ++x) {
            for (int y = 0; y < sy; ++y) {
                int x1, y1;
                if ((x + y) % 2 == 0) {
                    x1 = (x+y) / 2;
                    y1 = N + (x-y) / 2;
                } else {
                    x1 = (x+1+y) / 2;
                    y1 = N + (x+1-y) / 2;
                }
                cout << "RGBY"[((x1/r)%2)*2 + ((y1/r)%2)];
            }
            cout << "\n";
        }
    }

    return 0;
}
