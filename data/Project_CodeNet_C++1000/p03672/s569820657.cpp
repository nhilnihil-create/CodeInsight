#include <bits/stdc++.h>

#include <iostream>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    int output = 0;
    for (int start = 0; start < S.length(); start++) {
        int max = 0;
        for (int end = start; end < S.length() - start; end++) {
            int tmp = 0;
            if ((end - start + 1) % 2 != 1) continue;
            for (int i = 0; i < (end - start + 1) / 2; i++) {
                if (S[start + i] == S[start + i + (end - start + 1) / 2]) {
                    tmp++;
                } else {
                    tmp = 0;
                    break;
                }
            }
            tmp *= 2;
            // cout << tmp << "::";
            // for (int i = start; i < end; i++) {
            // cout << S[i];
            // }
            // cout << endl;
            if (max < tmp) max = tmp;
        }
        if (output < max) output = max;
    }

    cout << output << endl;
    return 0;
}
