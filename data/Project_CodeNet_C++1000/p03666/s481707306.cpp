#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool f(long long l, long long r, long long a, long long b) {
    long long A = max(l, a);
    long long B = min(r, b);
    return B - A > 0;
}

int main() {
    long long A, B;
    long long C, D;

    long long N;
    cin >> N;
    cin >> A >> B >> C >> D;

    long long X = abs(A - B);
    for (int i = 0; i <= N - 1; i++) {
        long long L = C * i;
        long long R = D * i;
        long long U = (N - 1 - i) / 2;
        L -= U * (D - C);
        R += U * (D - C);
        if ((N - 1 - i) % 2 == 0) {
            if (L <= X && X <= R) {
                cout << "YES" << endl;
                return 0;
            }
        } else {

            if (f(L, R, X - D, X - C) || f(L, R, X + C, X + D)) {
                cout << "YES" << endl;
                return 0;
            }

        }
    }
    cout << "NO" << endl;
}
