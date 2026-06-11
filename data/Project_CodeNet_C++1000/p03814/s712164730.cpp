#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    int left;
    int right;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') {
            left = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            right = i;
            break;
        }
    }
    cout << right - left + 1 << endl;
}