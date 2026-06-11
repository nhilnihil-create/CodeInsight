#include <climits>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

class NumberString {
    public:
    static UInt Digits(Int number) {
        return to_string(number).length();
    }
};


int main(void) {
    Int n;
    cin >> n;
    Int sq = sqrt(n);

    Int ans = INT_MAX;
    for (Int i = 1; i <= sq; ++i) {
        if (n % i != 0) {
            continue;
        }
        Int len = NumberString::Digits(max(i, n / i));
        ans = min(ans, len);
    }
    cout << ans << endl;
    return 0;
}

