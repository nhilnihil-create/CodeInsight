#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int ans = 0, N = S.size();
    for (int i = 2; i < N; i += 2) {
        int x = N - i;
        string str = S.substr(0, x);
        if (str.substr(0, x / 2) == str.substr(x / 2)) {
            ans = x;
            break;
        }
    }

    cout << ans << endl;
}