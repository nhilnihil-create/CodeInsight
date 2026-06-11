#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for (int i = 0; i < t; ++i) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    int mx = *max_element(a.begin(), a.end());
    cout << max(0, mx - 1 - (sum - mx)) << endl;
}
