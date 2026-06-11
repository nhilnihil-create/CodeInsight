#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int lowerStayDays = 0;
    int normalStayDays = 0;

    if (N >= K) {
        lowerStayDays = K;
        normalStayDays = N - K;
    } else {
        lowerStayDays = N;
    }

    int total = X * lowerStayDays + Y * normalStayDays;

    cout << total << endl;

    return 0;
}