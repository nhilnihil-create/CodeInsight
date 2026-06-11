/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> twos(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 4 == 0) {
            twos[2]++;
        }
        else if (x % 2 == 0) {
            twos[1]++;
        }
        else {
            twos[0]++;
        }
    }
    
    if (twos[2] + 1 < twos[0]) {
        cout << "No" << '\n';
    }
    else if (twos[2] < twos[0] && twos[1] > 0) {
        cout << "No" << '\n';
    }
    else if (twos[2] == 0 && twos[0] > 0) {
        cout << "No" << '\n';
    }
    else {
        cout << "Yes" << '\n';
    }
    return 0;
}