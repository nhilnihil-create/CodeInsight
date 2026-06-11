#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int numOfColor = 0;
    if (a == b && b == c) {
        numOfColor = 1;
    } else if (a != b && a != c && b != c) {
        numOfColor = 3;
    } else {
        numOfColor = 2;
    }

    cout << numOfColor << endl;
    
    return 0;
}