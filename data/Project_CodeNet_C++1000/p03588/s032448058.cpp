#include <iostream>
using namespace std;
int main() {
    int N, maxA = 0, ans;
    cin >> N;
    for (int i = 0, A, B; i < N; i++) {
        cin >> A >> B;
        if (A > maxA) {
            maxA = A;
            ans = A + B;
        }
    }
    cout << ans << endl;
}
