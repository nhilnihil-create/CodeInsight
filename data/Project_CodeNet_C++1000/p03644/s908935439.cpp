#include <bits/stdc++.h>
using namespace std;

int div2(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 0) {
            cnt++;
            n /= 2;
        }
        else {
            break;
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;

    int maximum = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        if (maximum < div2(i) || i == 1) {
            ans = i;
            maximum = div2(i);
        }
    }
    cout << ans << endl;
}