#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int four = 0;
    int two = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 4 == 0) four++;
        else if (x % 2 == 0) two++;
    }
    n -= (two % 2 == 0 ? two : two - 1);
    cout << (n / 2 <= four ? "Yes" : "No") << endl;
}
