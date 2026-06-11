#include <bits/stdc++.h>
using namespace std;

int main( )
{
    int a, b;
    cin >> a >> b;
    if (a + b >= 10) {
        cout << "error\n";
        return 0;
    }
    cout << (a + b) << '\n';
    return 0;
}
