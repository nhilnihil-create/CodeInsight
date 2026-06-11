#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx, dy = ty - sy;
    for (int i = 0; i < dx; i++) cout << 'R';
    for (int i = 0; i < dy; i++) cout << 'U';
    for (int i = 0; i < dx; i++) cout << 'L';
    for (int i = 0; i < dy; i++) cout << 'D';
    cout << 'D';
    for (int i = 0; i < dx + 1; i++) cout << 'R';
    for (int i = 0; i < dy + 1; i++) cout << 'U';
    cout << 'L' << 'U';
    for (int i = 0; i < dx + 1; i++) cout << 'L';
    for (int i = 0; i < dy + 1; i++) cout << 'D';
    cout << 'R' << endl;
}