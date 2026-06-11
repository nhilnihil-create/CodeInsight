#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
const ll N = 1234567;

int n;
ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    rep(i , 1 , n) a[i] += a[i - 1];

    ll maxi = LLONG_MAX;
    rep(i , 1 , n - 1) {
        maxi = min(maxi , abs(a[i] - a[n] + a[i]));
    }
    cout << maxi << endl;
    return 0;
}
