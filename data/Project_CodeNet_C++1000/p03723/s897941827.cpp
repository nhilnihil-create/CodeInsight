#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n)  FOR(i, 0, n)
#define ASC(c) sort((c).begin(), (c).end())
#define DESC(c) sort((c).begin(), (c).end(), greater<int>())

#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == b && a == c && b == c) {
        if (a % 2 == 0) cout << -1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int ta = a, tb = b, tc = c;
        a = (tb + tc) / 2;
        b = (ta + tc) / 2;
        c = (ta + tb) / 2;
        ans++;
    }
    cout << ans << endl;
}
