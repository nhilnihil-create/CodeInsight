#include <bits/stdc++.h>
using namespace std;

// g == 0
// p == 1

int main() {
    string s;
    cin >> s;
    int N, P = 0;
    N = s.length();
    for (int i = 0; i < N; i++) {
        if (s.at(i) == 'p') {
            P++;
        }
    }
    int point;
    point = N/2 - P;
    cout << point << endl;
    return 0;
}
