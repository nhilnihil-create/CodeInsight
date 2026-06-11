#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    char a, b;
    cin >> a >> b;
    if (a == 'H' && b == 'H')
        cout << 'H' << endl;
    else if (a == 'H' && b == 'D')
        cout << 'D' << endl;
    else if (a == 'D' && b == 'H')
        cout << 'D' << endl;
    else
        cout << 'H' << endl;
    return 0;
}