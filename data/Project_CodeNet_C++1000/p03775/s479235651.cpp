#include <bits/stdc++.h>

using namespace std;

static int func (long long A, long long B){
    int a = 0, b = 0;
    while ( A > 0 ) {
        A /= 10;
        a++;
    }
    while ( B > 0 ) {
        B /= 10;
        b++;
    }
    return max(a, b);
}

int main (void) {
    long long N;
    cin >> N;

    long long A = 1, B = N;
    for ( long long i = 2; i*i <= N; i++ ) {
        if ( N % i == 0 ) {
            A = i;
            B = N / i;
        }
    }

    cout << func(A, B) << endl;
    return 0;
}
