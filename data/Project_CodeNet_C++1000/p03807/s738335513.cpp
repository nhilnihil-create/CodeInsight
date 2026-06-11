// 偶数二つ → 偶数1つ
// 奇数二つ → 偶数1つ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int Odd = 0, Even = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (A % 2)
            ++Odd;
        else
            ++Even;
    }
    Even += Odd / 2;
    Odd %= 2;
    if (Odd == 0) {
        if (Even)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        if (Even == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}