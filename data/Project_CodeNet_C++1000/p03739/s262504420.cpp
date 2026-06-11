/**
 *    author:  FromDihPout
 *    created: 2020-07-25
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long pos = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 0 && sum <= 0) {
            pos += 1 - sum;
            sum = 1;
        }
        else if (i % 2 == 1 && sum >= 0) {
            pos += sum - (-1);
            sum = -1;
        }
    }
    
    long long neg = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 1 && sum <= 0) {
            neg += 1 - sum;
            sum = 1;
        }
        else if (i % 2 == 0 && sum >= 0) {
            neg += sum - (-1);
            sum = -1;
        }
    }
    
    cout << min(pos, neg) << '\n';
    return 0;
}