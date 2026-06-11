#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for(int i = 0; i < t; i++) {
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    vector<int> rui(t + 1);
    for(int i = 0; i < t; i++) {
        rui[i + 1] = rui[i] + a[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i < t; i++) {
        ans = min(ans, abs(rui[t] - 2 * rui[i]));
    }
    cout << max(0, ans - 1) << endl;
}