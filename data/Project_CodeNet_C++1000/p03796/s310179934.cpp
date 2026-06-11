#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, power = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        power *= i + 1;
        power %= 1000000007L;
    }
    cout << power << endl;
}