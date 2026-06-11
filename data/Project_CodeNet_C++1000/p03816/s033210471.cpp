/**
 *    author:  FromDihPout
 *    created: 2020-06-24
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
    sort(a.begin(), a.end());
    
    int remaining = n;
    int left = 0, right = n - 1;
    while (right - left > 1) {
        if (a[left + 1] != a[left]) {
            left++;
        }
        else if (a[right - 1] != a[right]) {
            right--;
        }
        else {
            left++;
            right--;
            remaining -= 2;
        }
    }
    
    if (a[left] == a[right] && left != right) {
        remaining -= 2;
    }
    cout << remaining << endl;
    return 0;
}