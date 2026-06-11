#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    set<int> se;
    se.insert(0);

    for (int i = 0; i < N; ++i) {
        set<int> nse = se;
        int x;
        cin >> x;
        for (int y : se)
            nse.insert(x + y);

        se = nse;
    }
    
    int ans = 0;
    for (auto itr = se.rbegin(); itr != se.rend(); ++itr) {
        auto x = *itr;
        if (x % 10 != 0) {
            ans = x;
            break;
        }
    }
    cout << ans << endl;
}
