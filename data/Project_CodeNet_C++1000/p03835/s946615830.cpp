#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int k, s;
    cin >> k >> s;

    int res = 0;
    for (int x = 0; x <= k ; ++x) {
        for (int y = 0; y <= k ; ++y) {
            if (s - x - y <= k && s - x - y >= 0) ++res;
        }
    }

    cout << res << endl;
}
