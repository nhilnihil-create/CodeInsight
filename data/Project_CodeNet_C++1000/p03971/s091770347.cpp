#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    int clrCount = 0, foreignCount = 1;
    string S;
    cin >> N >> A >> B >> S;

    for (auto i = 0; i < S.size(); i++) {
        switch (S[i]) {
            case 'a':
                if (clrCount < A + B) {
                    cout << "Yes" << endl;
                    clrCount++;
                } else {
                    cout << "No" << endl;
                }
                break;

            case 'b':
                if (clrCount < A + B && foreignCount <= B) {
                    cout << "Yes" << endl;
                    clrCount++;
                    foreignCount++;
                } else {
                    cout << "No" << endl;
                }
                break;
            default:
                cout << "No" << endl;
        }
    }
}