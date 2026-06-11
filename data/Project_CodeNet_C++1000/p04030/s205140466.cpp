#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
    ll i, j, k;
    string s, ans = "";
    cin >> s;
    for(auto c : s) {
        if(c != 'B') {
            ans += c;
        } else {
            if(ans.length() > 0) {
                ans = ans.substr(0, ans.length() - 1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
