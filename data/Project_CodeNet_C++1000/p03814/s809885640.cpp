#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int begin, end;
    int N = s.size();
    for (int i = 0; i < N; i++) {
        if (s.at(i) == 'A') {
            begin = i;
            break;
        }
    }
    for (int i = N - 1; i > 0; i--) {
        if (s.at(i) == 'Z') {
            end = i;
            break;
        }
    }
    cout << end - begin + 1 << endl;
}
