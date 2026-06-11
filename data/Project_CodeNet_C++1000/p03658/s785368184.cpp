#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    sort(all(l), greater<int>());
    int sum = 0;
    for(int i = 0; i < k; i++) sum += l[i];
    cout << sum << endl;
}
