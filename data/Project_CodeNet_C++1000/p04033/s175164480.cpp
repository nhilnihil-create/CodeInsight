#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (0 >= a && 0 <= b) {
        cout << "Zero\n";
        return 0;
    } 
    if (a > 0) {
        cout << "Positive\n";
        return 0;
    }
    int cnt = b - a + 1;
    if (cnt % 2 == 0) {
        cout << "Positive\n";
        return 0;
    } else {
        cout << "Negative\n";
    }
    return 0;
}
