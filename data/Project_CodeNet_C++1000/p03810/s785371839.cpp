#include <iostream>
#include <vector>
using namespace std;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }

bool solve(vector<int> A) {
    long long sum = 0;
    int odd = 0;
    bool ichi = false;
    for (int i = 0; i < A.size(); ++i) {
        sum += A[i] - 1;
        if (A[i] & 1) ++odd;
        if (A[i] == 1) ichi = true;
    }
    if (ichi) {
        if (sum % 2 == 0) return false;
        else return true;
    }
    else if (odd > 1) {
        if (sum % 2 == 0) return false;
        else return true;
    }
    else {
        if (sum % 2 == 1) return true;
        for (int i = 0; i < A.size(); ++i) if (A[i] & 1) --A[i];
        long long g = A[0];
        for (int i = 0; i < A.size(); ++i) g = GCD(g, A[i]);
        for (int i = 0; i < A.size(); ++i) A[i] /= g;
        if (!solve(A)) return true;
        else return false;
    }
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    if (solve(A)) puts("First");
    else puts("Second");
}