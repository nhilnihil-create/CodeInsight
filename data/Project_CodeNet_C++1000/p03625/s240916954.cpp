/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    
    long long area = 0;
    int side = -1;
    for (int i = 0; i < n-1; i++) {
        if (a[i] == a[i+1] && side == -1) {
            side = a[i];
            i++;
        }
        else if (a[i] == a[i+1]) {
            area = (long long) side * a[i];
            break;
        }
    }
    cout << area << '\n';
    return 0;
}