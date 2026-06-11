#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    int confirm = 0, bcnt = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'a' && confirm < A + B) {
            cout << "Yes" << endl;
            confirm++;
        }
        else if (S.at(i) == 'b' && confirm < A + B) {
            if (bcnt < B) {
                cout << "Yes" << endl;
                bcnt++;
                confirm++;
            }
            else {
                cout << "No" << endl;
                bcnt++;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
}