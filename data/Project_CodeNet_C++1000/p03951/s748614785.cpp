#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main() {
    int N, i; cin >> N;
    int ol = 0, key = 0;;
    string s, t; cin >> s >> t;
    for (i = 0; i < N; i++) {
        int index = i;
        for (int j = 0; j < N - i; j++) {
            if (s.at(index) == t.at(j)) {
                ol++; index++;
                key = ol;
                if (index == N) {
                    cout << 2 * N - key << endl;
                    return 0;
                }
            } else break;
        }
        ol = 0;
    }
    cout << 2 * N - key << endl;
}