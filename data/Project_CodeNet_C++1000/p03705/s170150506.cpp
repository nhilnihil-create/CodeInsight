#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, A, B; cin >> N >> A >> B;
    if (A > B || (N==1 && A != B)) {
        cout << 0 << endl;
        return 0;
    }

    ll low = (N - 1) * A + B;
    ll hig = A + (N - 1) * B;
    cout << hig - low + 1 << endl;
}
