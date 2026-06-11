#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int count[26] = {0};
    for (int i = 0; i < N; i++) {
        count[S[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] == 0) {
            printf("%c\n", 'a' + i);
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}