#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main() {
    fastio;
    int a, b;
    cin >> a >> b;

    if ((a <= 0 && b >= 0) || (a == 0 || b == 0)) cout << "Zero";
    else if (a > 0 && b > 0) cout << "Positive";
    else if (a < 0 && b > 0) {
        if (abs(a) % 2 != 0) cout << "Negative";
        else cout << "Positive";
    }
    else if (a < 0 && b < 0) {
        if (abs(a) % 2 != 0) {
            if (abs(b) % 2 != 0) cout << "Negative";
            else cout << "Positive";
        }
        else {
            if (abs(b) % 2 != 0) cout << "Positive";
            else cout << "Negative";
        }
    }

    return 0;
}