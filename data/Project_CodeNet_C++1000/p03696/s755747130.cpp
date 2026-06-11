#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    string S;
    cin >> N >> S;

    int n_l = 0;
    int n_r = 0;
    for ( int i = 0; i < N; i++ ) {
        if ( S.at(i) == '(' ) {
            n_l++;
        }
        else if ( n_l == 0 ) {
            n_r++;
        }
        else {
            n_l--;
        }
    }

    for ( int i = 0; i < n_r; i++ ) {
        cout << '(';
    }
    cout << S;
    for ( int i = 0; i < n_l; i++ ) {
        cout << ')';
    }
    cout << endl;

    return 0;
}
