#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    int max_count = 0;
    int now = 0;
    for (int i=0; i<N; i++) {
        if (S[i] == 'I') {
            now += 1;
        } else {
            now -= 1;
        }

        if (now > max_count) {
            max_count = now;
        }
    }

    cout << max_count << endl;
    return 0;
}