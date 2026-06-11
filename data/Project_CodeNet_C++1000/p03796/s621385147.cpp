#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N;
    cin >> N;
    long long sum = 1LL;
    for (int i=1; i <= N; i++) {
        sum = sum *i;
        sum = sum % int(pow(10, 9.0) + 7);
    }

    cout << sum << endl;
    return 0;
}