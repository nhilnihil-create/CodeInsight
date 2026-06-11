#include <climits>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;


// 基本的な演算
namespace BasicMath {
    // 数字の桁を求める
    static UInt Digits(UInt number);

    UInt Digits(UInt number) {
        return to_string(number).length();
    }
}
using namespace BasicMath;

int main(void) {
    Int n;
    cin >> n;
    Int sq = sqrt(n);

    Int ans = INT_MAX;
    for (Int i = 1; i <= sq; ++i) {
        if (n % i != 0) {
            continue;
        }
        Int len = Digits(max(i, n / i));
        ans = min(ans, len);
    }
    cout << ans << endl;
    return 0;
}

