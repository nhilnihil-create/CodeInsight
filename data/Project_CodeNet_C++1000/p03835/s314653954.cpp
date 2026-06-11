#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;

    int count = 0;

    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int num = S - (x + y);
            if (0 <= num && num <= K) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}