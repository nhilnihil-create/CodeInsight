#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int x, y = 0;
    cin >> x;
    for (int i = 1; ; i++) {
        y += i;
        if (y >= x) {cout << i; return 0;}
    }
}
