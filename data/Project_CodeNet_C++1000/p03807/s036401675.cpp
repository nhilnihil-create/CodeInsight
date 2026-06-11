// Addition
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, odd = 0, even = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 1) odd++;
    }
    even = N - odd;
    bool can = true;
    if (odd % 2 == 1) can = false;
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;

}