#include <bits/stdc++.h>
using namespace std;
//typedef int64_t int;
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise cout.precision(10); cout << fixed;
#define pb push_back
#define mk make_pair
#define endl "\n"
#define int int64_t
#define ll long long
#define in(num,n) std::vector<int> num(n); for (int i = 0; i < n; i++)cin >> num[i]
const ll Inf = 1e9 + 7;
void solve() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int sum = 0;
    if (n > k) {
        cout << k*x + (n - k)*y << endl;
    } else {
        cout << n*x << endl;
    }



}


int32_t main()
{
    fastio;
    precise;
    solve();
    return 0;
}