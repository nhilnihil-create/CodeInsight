#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    long long A, B, C;
    long long ans;

    cin >> A >> B >> C;

    if (A*B*C % 2 == 0) {
        cout << 0 << endl;
    } else {
        ans = min({A*B, B*C, C*A});
        cout << ans << endl;
    }
}
