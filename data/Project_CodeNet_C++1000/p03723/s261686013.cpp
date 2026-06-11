#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a, b, c,cnt=0;
    int aa, bb, cc;
    cin >> a >> b >> c;
    while (1) {
        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)break;
        aa = a / 2, bb = b / 2, cc = c/2;
        a = bb + cc, b = aa + cc, c = aa + bb;
        cnt++;
        if (cnt > 10000) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}