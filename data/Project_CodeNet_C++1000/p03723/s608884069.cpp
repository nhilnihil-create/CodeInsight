#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, cnt = 0, x, y, z;
    cin >> a >> b >> c;
    if(a%2 || b%2 || c%2) {
        cout << 0 << endl;
        return 0;
    }
    if(a == b && b == c) {
        cout << -1 << endl;
        return 0;
    }
    while(!(a%2) && !(b%2) && !(c%2)) {
        x = b/2 + c/2;
        y = a/2 + c/2;
        z = a/2 + b/2;
        a = x;
        b = y;
        c = z;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
