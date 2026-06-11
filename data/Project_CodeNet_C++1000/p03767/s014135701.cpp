#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n, a;
    cin >> n;
    vector<int>an(n * 3);
    rep(i, n * 3)cin >> an[i];
    sort(all(an));
    ll sum1=0, sum2=0,sum3=0;
    for (int i = n; i < 2 * n; i++)sum1 += an[i];
    for (int i = 1; i < 3 * n; i += 3)sum2 += an[i];
    for (int i = n; i < 3 * n; i += 2)sum3 += an[i];
    cout << max(sum3,max(sum1, sum2)) << endl;
}