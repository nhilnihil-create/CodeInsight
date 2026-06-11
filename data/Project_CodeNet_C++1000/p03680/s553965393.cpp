#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    vector<bool> flag(N, false);
    for (int i = 0; i < N; i++) cin >> A[i];
    int s = 1, ans = 0, cnt = 0;
    while(true) {
        if (flag[s - 1]) {
            ans = -1; break;
        }
        if (s == 2) {
            ans = cnt; break;
        }
        flag[s - 1] = true;
        cnt++, s = A[s - 1];
    }
    cout << ans << endl;
}
