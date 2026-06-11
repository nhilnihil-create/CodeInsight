#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

// ユークリッドの互除法
// 最大公約数を求めるアルゴリズム
Int Euclidean(Int a, Int b) {
    if (b == 0) {
        return a;
    } else {
        if (a < b) {
            std::swap(a, b);
        }
        return Euclidean(b, a % b);
    }
}

int main(void) {
    Int n;
    cin >> n;
    Int result = 1;
    Int input;
    for (Int i = 0; i < n; ++i) {
        cin >> input;
        Int gcd = Euclidean(result, input);
        result /= gcd;
        result *= input;
    }
    cout << result << endl;
    return 0;
}

