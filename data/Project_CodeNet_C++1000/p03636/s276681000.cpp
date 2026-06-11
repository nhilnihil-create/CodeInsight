#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, S_s, S_e;
    int S_size;
    ostringstream oss;

    cin >> S;

    S_s = S[0];
    S_size = S.size();
    S_e = S[S_size -1];
    oss << S_size - 2;

    cout << S_s + oss.str() + S_e << endl;
}