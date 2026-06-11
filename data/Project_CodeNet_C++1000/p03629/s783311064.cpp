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

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
    ll i, j, k;
    string A;
    cin >> A;
    ll N = A.length();
    vector<vll> P;
    for(i = 0; i < 26; i++) {
        char c = 'a' + i;
        vll Pi(N, 0);
        ll p = N;
        for(j = N - 1; j >= 0; j--) {
            if(A[j] == c) {
                p = j;
            }
            Pi[j] = p;
        }
        P.push_back(Pi);
    }
    vll dp(N + 2, 0);
    dp[N + 1] = 0;
    dp[N] = 1;
    for(i = N - 1; i >= 0; i--) {
        ll minl = INF;
        for(j = 0; j < 26; j++) {
            // char c = 'a' + j;
            minl = min(minl, 1 + dp[P[j][i] + 1]);
        }
        dp[i] = minl;
    }
    string ans = "";
    ll p = 0;
    while(1) {
        for(j = 0; j < 26; j++) {
            char c = 'a' + j;
            if(dp[P[j][p] + 1] + 1 == dp[p]) {
                ans += c;
                p = P[j][p] + 1;
                if(p >= N) {
                    cout << ans << endl;
                    return 0;
                }
                break;
            }
        }
    }
}
