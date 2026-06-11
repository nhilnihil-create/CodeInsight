#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n;
    int a,b,min1=0,min2;
    cin >> n;
    rep(i, n) {
        cin >> a >> b;
        if (a > min1) {
            min1 = a, min2 = b;
        }
    }
    int cnt = min1 + min2;
    cout << cnt << endl;
    return 0;
}
