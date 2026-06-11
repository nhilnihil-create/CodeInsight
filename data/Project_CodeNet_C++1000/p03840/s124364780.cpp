#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;

    long r = 0;
    r += o; o -= o;

    if(((i&1) + (j&1) + (l&1) >= 2) && (i&&j&&l))
        r+=3, i--, j--, l--;
    r += i/2 * 2; i -= i/2*2;
    r += j/2 * 2; j -= j/2*2;
    r += l/2 * 2; l -= l/2*2;
    cout << r << endl;
}
