// Airport Bus
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];
    sort(T.begin(), T.end());

    int bus = 0;
    for (int i = 0; i < N;) {
        int j = 0;
        while (j < C) {
            if (T[i+j] - T[i] <= K) {
                j++;
            } else {
                break;
            }
        }
        bus++;
        i += j;
    }
    cout << bus << endl;
}