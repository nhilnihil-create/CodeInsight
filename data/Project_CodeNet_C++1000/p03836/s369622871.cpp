#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int sx,sy,tx,ty;
    cin >> sx >> sy >>tx >>ty;
    int dx = tx-sx;
    int dy = ty-sy;
    cout << string(dy,'U') << string(dx,'R');
    cout << string(dy,'D') << string(dx,'L');
    cout << string(1,'L') <<string(1+dy,'U') << string(1+dx,'R') << string(1,'D');
    cout << string(1,'R') << string(1+dy,'D') <<string(1+dx,'L') << string(1,'U') << endl;

    return 0;
}