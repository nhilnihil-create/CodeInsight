#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    long long diff = B - A;
    long long l = -(N - 1) * D;
    long long r = -(N - 1) * C;
    for(int i=0; i<N-1; ++i) {
        if(diff >= l && diff <= r) {
            cout << "YES" << endl;
            return 0;
        } else {
            l += C + D;
            r += C + D;
        }
    }

    cout << "NO" << endl;
    return 0;
}