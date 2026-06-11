#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long sum = 1;
    for (int i = 1; i <= N; i++) {
        sum *= i;
        if (sum >= 1000000007) {
            sum %= 1000000007;
        }
    }
    cout << sum  << endl;
}