#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for (int i=0;i<T;i++) cin >> a[i];
    sort(a.rbegin(),a.rend());
    int ans = max(a[0] - 1 - (K - a[0]), 0);
    cout << ans << "\n";
}