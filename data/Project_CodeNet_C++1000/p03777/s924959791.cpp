#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char a,b;

    cin >> a >> b;
    if(a == 'D') {
        b = (b == 'D') ? 'H' : 'D';
    }

    cout << b << "\n";
    return 0;
}
