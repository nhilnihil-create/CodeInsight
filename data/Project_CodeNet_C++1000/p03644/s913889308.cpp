#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int ans = 1;
    int mcnt = 0;
    for (int num = 1; num <= n; num++) {
        int cnt = 0;
        int i = num;
        while (i % 2 == 0) {
            i /= 2;
            cnt++;
        }
        if (mcnt < cnt) {
            mcnt = cnt;
            ans = num;
        }
    }
    cout << ans << endl;
    return 0;
}