#include <iostream>
#define int long long
using namespace std;

signed main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    
    B -= A;
    A = 0;
    bool judge = false;
    for (int i = 0; i < N; ++i) {
        int up = D * i - C * (N - 1 - i);
        int down = C * i - D * (N - 1 - i);
        if (down <= B && B <= up) judge = true;
        up *= -1;
        down *= -1;
        if (up <= B && B <= down) judge = true;
    }
    
    if (judge) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
