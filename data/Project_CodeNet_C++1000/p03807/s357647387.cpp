#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint N;
    cin >> N;
    vector<int> A(N, 0);
    int numGu = 0, numKi = 0;
    for (size_t i=0; i<N; ++i) {
        cin >> A[i];
        if (A[i] % 2 == 0) ++numGu;
        else ++numKi;
    }

    // 奇数をまとめて偶数へ(奇数+奇数=偶数だから)
    numGu += numKi / 2;
    // 奇数の残り分
    numKi = numKi % 2;

    // 偶数をまとめる
    if (numGu > 0) numGu = 1;

    if (numGu + numKi == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
