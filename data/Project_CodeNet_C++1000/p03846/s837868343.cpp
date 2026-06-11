/**
 *    author:  FromDihPout
 *    created: 2020-06-10
**/

#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;

int expo(int base, int e) {
    if (e == 0) {
        return 1;
    }
    else if (e & 1) {
        int half = expo(base, e / 2);
        return (int) ((long long) base * half * half % MOD);
    }
    else {
        int half = expo(base, e / 2);
        return (int) ((long long) half * half % MOD);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    
    if (n & 1) {
        if (a[0] != 1) {
            cout << 0 << '\n';
            return 0;
        }
        for (int i = 2; i < n; i+=2) {
            if (a[i] != 2) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    else {
        for (int i = 1; i < n; i+=2) {
            if (a[i] != 2) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    
    cout << expo(2, n / 2) << endl;
    return 0;
}