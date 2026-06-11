#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, k,x, dist = 0,adist,bdist;
    cin >> n >> k;
    rep(i, n) {
        cin >> x;
        adist = x * 2;
        bdist = abs(k - x) * 2;
        dist += min(adist, bdist);
    }
    cout << dist << endl;
    return 0;
}