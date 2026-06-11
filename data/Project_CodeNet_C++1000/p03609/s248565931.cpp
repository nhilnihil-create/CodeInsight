#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t X;
    int64_t t;
    cin >> X >> t;

    X -= t;
    if( X < 0) X =0;
    cout << X << "\n";
    

    return 0;
}
