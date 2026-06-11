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
    int cnt = 0;
    cin >> n;
    vector<int>rabbit(n);
    rep(i, n)cin >> rabbit[i];
    rep(i, n) {
        if (i == rabbit[rabbit[i] - 1] - 1)cnt++;
    }
    cout << cnt/2 << endl;
}
