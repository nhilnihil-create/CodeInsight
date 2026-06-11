#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, pos, mid;
    int sum = 0;
    cin >> n >> k;
    mid = k/2 + k%2;
    for (int i = 0; i < n; i++) {
        cin >> pos;
        if (pos < mid) sum += pos * 2;
        else sum += (k - pos) * 2;
    }
    cout << sum << endl;
}
