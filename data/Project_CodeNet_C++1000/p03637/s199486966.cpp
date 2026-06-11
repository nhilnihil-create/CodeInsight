#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int four, two, other;
    four = two = other = 0;
    for (auto x : a) {
        if (x%4 == 0) four++;
        else if (x%2 == 0) two++;
    }
    other = n - (two + four);
    if (two) {
        cout << (other <= four ? "Yes" : "No") << endl;
    } else {
        cout << (other <= four + 1 ? "Yes" : "No") << endl;
    }

    return 0;
}