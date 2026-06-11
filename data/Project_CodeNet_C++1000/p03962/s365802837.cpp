#include <bits/stdc++.h>
using namespace std;

int main() {
    int c1,c2,c3; cin >> c1 >> c2 >> c3;
    if(c1==c2 && c2==c3) cout << 1 << endl;
    else if(c1==c2 || c2==c3 || c1==c3) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}
