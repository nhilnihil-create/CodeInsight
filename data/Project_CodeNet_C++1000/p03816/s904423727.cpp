#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    rep(i, N) {
        int a;
        cin >> a;
        mp[a]++;
    }

    int k = mp.size();
    if (k % 2) {
        cout << k << endl;
    } else {
        cout << k - 1 << endl;
    }
}