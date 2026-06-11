#include <iostream>
#include <utility>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

namespace BasicMath {
    // 最大公約数を求める(ユークリッドの互除法)
    static UInt GreatestCommonDivisor(UInt a, UInt b);
    // 最小公倍数を求める
    static UInt LeastCommonMultiple(UInt a, UInt b);

    UInt GreatestCommonDivisor(UInt a, UInt b) {
        if (b == 0) {
            return a;
        } else {
            if (a < b) {
                std::swap(a, b);
            }
            return GreatestCommonDivisor(b, a % b);
        }
    }
    UInt LeastCommonMultiple(UInt a, UInt b) {
        Int gcd = GreatestCommonDivisor(a, b);
        return a / gcd * b;
    }
#define GCD GreatestCommonDivisor
#define LCM LeastCommonMultiple

}
using namespace BasicMath;

int main(void) {
    Int n;
    cin >> n;
    Int result = 1;
    Int input;
    for (Int i = 0; i < n; ++i) {
        cin >> input;
        result = LCM(result, input);
    }
    cout << result << endl;
    return 0;
}

