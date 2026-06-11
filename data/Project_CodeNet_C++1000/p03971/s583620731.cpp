#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    bool isok[100005] = {};
    int a, b; // 国内の通過人数，海外の通過人数
    a = b = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'a') {
            if (a + b < A + B) {
                isok[i] = true;
                a++;
            }
        } else if (S[i] == 'b') {
            if (a + b < A + B && b < B) {
                isok[i] = true;
                b++;
            }
        }
    }

    for (int i = 0; i < N; ++i)
        cout << (isok[i] ? "Yes" : "No") << endl;
}