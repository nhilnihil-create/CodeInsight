#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    vector<long long> tmp{A, B, C};
    sort(tmp.begin(), tmp.end());
    long long ABC = A * B * C;
    if (ABC % 2 == 0) {
        cout << 0 << endl;
    } else {
        cout << abs((tmp[0] * tmp[1] * (tmp[2] / 2)) - (tmp[0] * tmp[1] * (tmp[2] / 2 + 1))) << endl;
    }

    return 0;
}