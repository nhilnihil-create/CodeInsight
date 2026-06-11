// Sorted Arrays
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<long int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    if (N == 1) {cout << 1 << endl; return 0;}

    bool up = A[0] < A[1];
    int count = 1;
    vector<bool> x;
    for (int i = 0; i < N-1; i++) {
        if (A[i] == A[i+1]) continue;
        x.push_back(A[i] < A[i+1]);
    }
    for (int i = 0; i < x.size()-1; i++) {
        if (x[i] != x[i+1]) {
            i++;
            count++;
        }
    }
    cout << count << endl;
}
