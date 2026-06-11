#include <bits/stdc++.h>

using namespace std;

int main() {
    int X;
    cin >> X;

    int t = 1;
    long long sum = 0;
    while (sum < X) {
        sum += t;
        t++;
    }
    cout << t - 1 << endl;

    return 0;
}
