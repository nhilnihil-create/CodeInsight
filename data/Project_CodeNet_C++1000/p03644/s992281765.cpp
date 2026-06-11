#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, res = 0, max = 0;;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int tmp = i;
        int cnt = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            cnt++;
        }
        if (max <= cnt) {
            max = cnt;
            res = i;
        }
    }

    cout << res << endl;
}