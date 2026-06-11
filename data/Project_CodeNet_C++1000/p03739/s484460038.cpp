#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    long total1 = 0;
    long ans1 = 0;
    for (int i = 0; i < n; i++) {
        total1 += a.at(i);
        if (i % 2 == 0) {
            if (total1 <= 0) {
                ans1 += total1 * (-1) + 1;
                total1 = 1;
            }
        } else {
            if (total1 >= 0) {
                ans1 += total1 + 1;
                total1 = -1; 
            }
        }
    }

    long total2 = 0;
    long ans2 = 0;
    for (int i = 0; i < n; i++) {
        total2 += a.at(i);
        if (i % 2 == 1) {
            if (total2 <= 0) {
                ans2 += total2 * (-1) + 1;
                total2 = 1;
            }
        } else {
            if (total2 >= 0) {
                ans2 += total2 + 1;
                total2 = -1; 
            }
        }
    }

    cout << min(ans1, ans2) << endl;

}