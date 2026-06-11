/**
 *    author:  FromDihPout
 *    created: 2020-07-29
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> range = {3200, 2800, 2400, 2000, 1600, 1200, 800, 400, 1};
    const int COLS = range.size();
    
    int n;
    cin >> n;
    vector<int> cnt(COLS);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < COLS; j++) {
            if (x >= range[j]) {
                cnt[j]++;
                break;
            }
        }
    }
    
    int unique = 0;
    for (int i = 1; i < COLS; i++) {
        unique += cnt[i] > 0;
    }
    
    if (unique == 0 && cnt[0] > 0) {
        cout << 1 << ' ';
    }
    else {
        cout << unique << ' ';
    }
    cout <<  unique + cnt[0] << '\n';
    return 0;
}