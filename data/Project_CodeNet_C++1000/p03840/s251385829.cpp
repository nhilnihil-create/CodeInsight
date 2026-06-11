#include <bits/stdc++.h>
using namespace std;

int main() {
    int I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;

    if (J > 0 && L > 0 && I > 0) {
        long long x = (long long)((I - 1) / 2) * 2 + O + ((J - 1) / 2) * 2 + ((L - 1) / 2) * 2 + 3;
        long long y = (long long)(I / 2) * 2 + O + (J / 2) * 2 + (L / 2) * 2;
        cout << max(x, y) << endl;
    } else {
        cout << ((I / 2) * 2 + O + (J / 2) * 2 + (L / 2) * 2) << endl;
    }
}
