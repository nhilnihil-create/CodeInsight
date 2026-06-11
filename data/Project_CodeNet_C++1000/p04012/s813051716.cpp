#include <bits/stdc++.h>

using namespace std;

char arr[26];

int main() {
    string w;
    cin >> w;

    for (char c : w) arr[c - 97]++;
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 != 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
