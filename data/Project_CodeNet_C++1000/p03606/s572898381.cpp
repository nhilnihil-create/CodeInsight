#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x, y;
    int sum;
    sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        sum += (y - x) + 1;
    }
    cout << sum << endl;

    return 0;
}