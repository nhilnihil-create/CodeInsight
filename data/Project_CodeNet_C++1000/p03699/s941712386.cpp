/**
 *    author:  FromDihPout
 *    created: 2020-07-29
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    vector<bool> score(sum+1);
    score[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum - a[i]; j >= 0; j--) {
            if (score[j]) {
                score[j + a[i]] = true;
            }
        }
    }
    
    for (int i = sum; i >= 0; i--) {
        if (score[i] && i % 10 != 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}