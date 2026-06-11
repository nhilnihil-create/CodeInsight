// Sequence
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int N;
    ll count1 = 0, count2 = 0;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll su = 0;
    for (int i = 0; i < N; i++) {
        su += A[i];
        if (i % 2 == 1) {
            if (su < 1) {
                count1 += -1 * su + 1;
                su = 1;
            }
        } else {
            if (su > -1) {
                count1 += su + 1;
                su = -1;
            }
        }
    }

    su = 0;
    for (int i = 0; i < N; i++) {
        su += A[i];
        if (i % 2 == 0) {
            if (su < 1) {
                count2 += -1 * su + 1;
                su = 1;
            }
        } else {
            if (su > -1) {
                count2 += su + 1;
                su = -1;
            }
        }
    }

    cout << min(count1, count2) << endl;
}