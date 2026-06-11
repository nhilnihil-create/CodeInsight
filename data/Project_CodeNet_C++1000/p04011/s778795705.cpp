
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, k, x, y, z;
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> y;
    
    z = ((k-n)<0 ? k:n) * x + ((n-k)>0 ? (n-k):0) * y;

    cout << z << "\n" << endl;
    return 0;
}

