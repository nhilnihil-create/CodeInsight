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
    ll a, b; cin >> a >> b;
    if ((a <= 0 && b >= 0) || (a == 0 || b == 0)) {
        cout << "Zero" << endl;
        return 0;
    }

    if ((a > 0 && b > 0) || (a == b)) {
        cout << "Positive" << endl;
        return 0;
    }
    if (b < 0) {
        if ((b - a) % 2 == 1) {
            cout << "Positive" << endl;
            return 0;
        } else {
            cout << "Negative" << endl;
            return 0;
        }
    }

}
