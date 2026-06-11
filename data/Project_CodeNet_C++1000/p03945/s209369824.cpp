#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    char c = S[0];
    int count = 0;
    for (int i=0; i < N; i++) {
        if (c != S[i]) {
            count += 1;
            c = S[i];
        }
    }

    cout << count << endl;
    return 0;
}