#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long power = 1;
    long c = 1000000007;

    for (int i = 1; i <= N; i++) {
        power *= i;
        power %= c;
    }
    cout << power << endl;
}
