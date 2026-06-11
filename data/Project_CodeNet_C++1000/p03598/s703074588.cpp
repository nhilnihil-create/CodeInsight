#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x <= abs(x - K)) {
            sum += x;
        }
        else {
            sum += abs(x - K);
        }
    }
    cout << 2 * sum << endl;
}
