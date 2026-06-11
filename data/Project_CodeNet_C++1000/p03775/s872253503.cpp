#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long num) {
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;  // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            // 素数ではない
            return false;
        }
    }
    // 素数
    return true;
}

int main() {
    //
    long long num;
    long long sNum;
    long long Min = 9999999;
    string a, b;

    cin >> num;

    if (IsPrime(num) == true) {
        cout << to_string(num).size();
        return 0;
    }

    for (long long i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            a = to_string(i);
            b = to_string(num / i);
            Min = min(Min,(long long)max(a.size(), b.size()));
        }
    }

    cout << Min;
    //
}