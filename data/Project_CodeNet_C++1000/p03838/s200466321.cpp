#include <iostream>
using namespace std;

long long x, y;
int main() {
    cin >> x >> y;
    long long res = 1LL << 60;
    if (x <= y) res = min(res, y - x);
    if (-x <= y) res = min(res, y + x + 1);
    if (x <= -y) res = min(res, -y - x + 1);
    if (-x <= -y) res = min(res, -y + x + 2);
    cout << res << endl;
}