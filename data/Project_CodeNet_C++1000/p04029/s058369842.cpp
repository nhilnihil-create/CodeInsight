#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 1; i < n+1; i++)

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    rep(i, N) {
        cnt += i;
    }

    cout << cnt << endl;

    return 0;
}