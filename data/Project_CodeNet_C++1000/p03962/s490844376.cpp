#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, c, z;
    cin >> a;
    cin >> b;
    cin >> c;
    
    if (a==b && a==c) { z = 1; }
    else if (a==b) { z = 2; }
    else if (a==c) { z = 2; }
    else if (b==c) { z = 2; }
    else { z = 3; }

    cout << z << "\n" << endl;
    return 0;
}