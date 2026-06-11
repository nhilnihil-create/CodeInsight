#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    ll oc = 0, sum1 = 0, ec = 0, sum2 = 0;
    rep(i, 0, n) {
        sum1 += v[i];
        if (i % 2 == 0) {
            while (0 <= sum1) {
                sum1--;
                oc++;
            }
        }
        else {
            while (sum1 <= 0) {
                sum1++;
                oc++;
            }
        }
    }
    rep(i, 0, n) {
        sum2 += v[i];
        if (i % 2 == 0) {
            while (sum2 <= 0) {
                sum2++;
                ec++;
            }
        }
        else {
            while (0 <= sum2) {
                sum2--;
                ec++;
            }
        }
    }
    cout << min(oc, ec) << endl;
    return 0;
}