#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    int a;
    int n_mult_four = 0;
    int n_even_else = 0;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        if ( a % 4 == 0 )
            n_mult_four++;
        else if ( a % 2 == 0 )
            n_even_else++;
    }

    if ( n_mult_four >= N / 2 ) {
        cout << "Yes" << endl;
        return 0;
    }
    else if ( n_even_else >= (N - n_mult_four * 2) ) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
