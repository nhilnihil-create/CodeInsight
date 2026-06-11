#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;

int main() {
    int n, num = 0;
    cin >> n;
    int l, r;

    for(int i=0; i<n; i++) {
        cin >> l >> r;
        num += r - l + 1;
    }
    cout << num << endl;
}