#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int n;
    cin >> n;
    Int sq = sqrt(n);

    Int ans = INT_MAX;
    for (Int i = 1; i <= sq; ++i) {
        if (n % i != 0) {
            continue;
        }
        Int len = to_string(max(i, n / i)).length();
        ans = min(ans, len);
    }
    cout << ans << endl;
    return 0;
}

