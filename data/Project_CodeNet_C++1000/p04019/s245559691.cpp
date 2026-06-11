#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<bool> check(4, false);
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == 'N') check[0] = true;
        if (S[i] == 'W') check[1] = true;
        if (S[i] == 'S') check[2] = true;
        if (S[i] == 'E') check[3] = true;
    }

    if (check[0] == check[2] && check[1] == check[3]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
