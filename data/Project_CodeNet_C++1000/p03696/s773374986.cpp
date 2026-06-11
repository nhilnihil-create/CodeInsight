#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int cnt[2] = {};
    for (int i = 0; i < N; ++i) {
        if (S[i] == '(') {
            ++cnt[0];
        } else {
            if (cnt[0]) --cnt[0];
            else ++cnt[1];
        }
    }
    for(int i = 0; i < cnt[1]; ++i)
        cout << '(';
    cout << S;
    for(int i = 0; i < cnt[0]; ++i)
        cout << ')';
    cout << endl;
}