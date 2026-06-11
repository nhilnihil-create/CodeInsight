#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    unsigned long long int a, b, x; cin >> a >> b >> x;
    unsigned long long int ans = b / x + 1;
    if (a != 0) ans -= (a - 1) / x + 1;
    cout << ans << endl;
}
