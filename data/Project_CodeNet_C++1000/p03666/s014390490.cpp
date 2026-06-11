#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
int main() {
    i64 N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    B = abs(B - A), A = 0;
    N--;
    for(int i = 0; i <= N; i++) {
        i64 X, Y;
        X = B + i * C, Y = B + i * D;
        if(Y - (N - i) * C >= 0 && X - (N - i) * D <= 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}