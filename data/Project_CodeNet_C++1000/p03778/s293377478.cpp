#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int w, a, b; cin >> w >> a >> b;
    if(a < b) cout << max(0, b - a - w) << endl;
    else cout << max(0, a - b - w) << endl;
}
