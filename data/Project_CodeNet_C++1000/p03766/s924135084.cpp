/**
    why I'm too lazy?
**/
#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb emplace_back
#define pp pop_back()
#define ll long long
#define ld long double
#define OK puts("OK");
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 1e6 + 10;
const int inf = 1e9 + 7;
const ll linf = 1e18 + 7;

ll n, dp[N], sum;

int main() {
    cin >> n;
    dp[1] = n;
    dp[2] = n * n % inf;
    for(int i = 3; i <= n; i++) {
        if(i > 3)
            sum = (sum + dp[i - 3]) % inf;
        dp[i] = (dp[i - 1] + (n - 1) * (n - 1) % inf + sum + (n - i + 2)) % inf;
    }
    cout << dp[n] << endl;
}
