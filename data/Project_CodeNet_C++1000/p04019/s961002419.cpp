#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int Ncnt = 0, Wcnt = 0, Scnt = 0, Ecnt = 0;
    for (int i = 0; i < S.length(); i++) {
        switch (S[i]) {
            case 'N': Ncnt++; break;
            case 'W': Wcnt++; break;
            case 'S': Scnt++; break;
            case 'E': Ecnt++; break;
        }
    }
    if ((Ncnt == 0 && Scnt > 0) || (Ncnt > 0 && Scnt == 0) || (Wcnt == 0 && Ecnt > 0) || (Wcnt > 0 && Ecnt == 0)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}