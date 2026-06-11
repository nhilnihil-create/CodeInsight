#include <iostream>
#include <cmath>
using namespace std;

long long N, A, B, C, D;
int main() {
    cin >> N >> A >> B >> C >> D;
    A *= 2, B *= 2, C *= 2, D *= 2;
    --N;
    long long diff = abs(A - B);
    long long gap = (C + D) / 2;
    long long center = 0;
    if (N & 1) center = gap;
    long long radius = (D - C) / 2 * N;

    bool ok = false;
    for (int i = 0; i < N*2; ++i) {
        long long left = center - radius, right = center + radius;
        if (right > D * N) break;
        if (left <= diff && diff <= right) ok = true;
        center += gap * 2;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}