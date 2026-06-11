#include <bits/stdc++.h>
using namespace std;
int main(void) {
    long long K;
    cin >> K;
    puts("50");
    for (int i = 0; i < 50; i++) {
        cout << i + (i + K) / 50 << " ";
    }
    return 0;
}