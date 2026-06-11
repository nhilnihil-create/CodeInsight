#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x%4 == 0) {
            sum++;
        }
        else {
            if(x%2 == 0) {
                sum2++;
            }
        }
    }

    if(sum + (sum2/2) >= n/2) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
