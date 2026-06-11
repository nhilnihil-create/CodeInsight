#include <bits/stdc++.h>

using namespace std;



int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += A[i];
    }
    int closeInt;
    if (total%N == 0) {
        closeInt = total/N;
    }
    else if (ceil( double(total)/N) - double(total)/N < double(total)/N - floor(double(total)/N)) {
        closeInt = int(ceil( double(total)/N));
    }
    else {
        closeInt = int(floor(double(total)/N));
    }
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cost += (closeInt - A[i]) * (closeInt - A[i]);
    }
    cout << cost;

    return 0;
}

