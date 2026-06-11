#include <bits/stdc++.h>
using  namespace std;

#define    ll     long long int

int main( )
{
    int n, i, j, k;
    int odd = 0, four = 0, two = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> j;
        if (j % 2) {
            odd++;
        }
        else if (j % 4 == 0) {
            four++;
        }
        else {
            two++;
        }
    }
    if (odd <= four) {
        cout << "Yes\n";
    }
    else if (odd - four == 1 && two == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}