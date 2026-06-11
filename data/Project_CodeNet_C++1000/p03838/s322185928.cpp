#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;

    int opCount = 0;
    if (abs(x) == abs(y)) {
        if (x == y)
            opCount = 0;
        else
            opCount = 1;
    } else if (abs(x) < abs(y)) {
        if (x < 0) opCount += 1;
        opCount += abs(y) - abs(x);
        if (y < 0) opCount += 1;
    } else {  // abs(x) > abs(y)
        if (x > 0) opCount += 1;
        opCount += abs(x) - abs(y);
        if (y > 0) opCount += 1;
    }
    cout << opCount << endl;
    return 0;
}
