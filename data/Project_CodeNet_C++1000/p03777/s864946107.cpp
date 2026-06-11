#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    char a , b;
    cin >> a >> b;
    if ( a == 'H' && b == 'H') {
        cout << 'H' << endl;
    }
    if ( a == 'H' && b == 'D') {
        cout << 'D' << endl;
    }
    if ( a == 'D' && b == 'H') {
        cout << 'D' << endl;;
    }
    if ( a == 'D' && b == 'D') {
        cout << 'H' << endl;
    }
}