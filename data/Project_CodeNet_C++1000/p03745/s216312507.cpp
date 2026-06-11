#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, cnt = 1, tmp; cin >> N >> tmp;
    int state = 0;
    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        if (state == -1) {
            if (tmp < x) {
                state = 0;
                cnt++;
            }
        } else if (state == 1) {
            if (tmp > x) {
                state = 0;
                cnt++;
            }
        } else {
            if (tmp < x) state = 1;
            else if (tmp > x) state = -1;
        }
        tmp = x;
    }
    cout << cnt << endl;
}