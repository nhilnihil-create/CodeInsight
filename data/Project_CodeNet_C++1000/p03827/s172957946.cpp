#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x = 0;
    string S;
    cin >> N >> S;

    vector<int> mem(N, 0);

    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'I') {
            x++;
            mem.at(i) = x;
        }
        else {
            x--;
            mem.at(i) = x;
        }
    }

    sort(mem.begin(), mem.end());
    reverse(mem.begin(), mem.end());
    if (0 <= mem.at(0)) {
        cout << mem.at(0) << endl;
    }
    else {
        cout << 0 << endl;
    }
    
}