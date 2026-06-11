#include <iostream>

using namespace std;

int main() {
    int n;
    int a[1000000];
    bool dp[1000000];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int index = 1, counter = 0;
    while (!dp[index]) {
        dp[index] = true;
        index = a[index];
        counter++;

        if (index == 2) {
            cout << counter << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}