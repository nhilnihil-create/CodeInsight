#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll>abc = { a,b,c };
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)cout << 0 << endl;
    else {
        sort(all(abc));
        cout << abc[0] * abc[1] << endl;
    }
}
