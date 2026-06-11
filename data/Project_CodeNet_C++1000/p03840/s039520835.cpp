#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;
    ll ans = 0;
    ans += ao;
    if ( ai > 0 ) {
        ans += (ai-1)/2 * 2;
        ai -= (ai-1)/2 * 2;
    }
    if ( aj > 0 ) {
        ans += (aj-1)/2 * 2;
        aj -= (aj-1)/2 * 2;
    }
    if ( al > 0 ) {
        ans += (al-1)/2 * 2;
        al -= (al-1)/2 * 2;
    }
    int c2 = 0, c1 = 0;
    if ( ai > 1 ) c2++;
    if ( aj > 1 ) c2++;
    if ( al > 1 ) c2++;
    if ( ai > 0 ) c1++;
    if ( aj > 0 ) c1++;
    if ( al > 0 ) c1++;
    if ( c1 == 3 && c2 <= 1 ) {
        ans += 3;
    } else  {
        ans += ai/2 * 2;
        ans += aj/2 * 2;
        ans += al/2 * 2;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}