#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a, b;
    cin >> a >> b;
    string p = "Positive", n = "Negative", z = "Zero";
    if (a <= 0 && b >= 0)cout << z << endl;
    else if (a > 0)cout << p << endl;
    else if (a < 0) {
        if (b < 0) {
            if (((abs(a - b)) + 1) % 2 == 0)cout << p << endl;
            else cout << n << endl;
        }
    }
    return 0;
}