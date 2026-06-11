#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll X;
    cin >> X;

    ll cnt = (X / 11) * 2;
    ll mod = X % 11;
    if (mod != 0) {
        if (mod <= 6) {
            cnt++;
        } else {
            cnt += 2;
        }
    }

    cout << cnt << endl;
}