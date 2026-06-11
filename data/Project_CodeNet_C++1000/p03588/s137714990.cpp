#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll>PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e4+7;
int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) {
        ll tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        ab[i] = make_pair(tmp_a, tmp_b);
    }
    sort(ab.begin(), ab.end());
    cout << ( ab[0].first - 1 ) + ( ab[ab.size()-1].first - ab[0].first + 1 ) + ab[ab.size()-1].second << endl;
    return 0;
}
