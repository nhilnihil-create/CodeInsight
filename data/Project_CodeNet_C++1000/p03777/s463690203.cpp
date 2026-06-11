#include <bits/stdc++.h>
using namespace std;

#define     ll     long long int

int main( )
{
    char a, b;
    cin >> a >> b;
    if (a == 'H') {
        cout << b << '\n';
    }
    else {
        if (b == 'H') {
            cout << "D\n";
        }
        else {
            cout << "H\n";
        }
    }
    return 0;
}
