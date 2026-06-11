#include <bits/stdc++.h>
using namespace std;

#define abs(a) (((a) < 0) ? (-(a)) : (a))
int main(void) {
    int x, a, b;
    cin >> x >> a >> b;

    if(abs(a-x) > abs(b-x)) {
        cout << "B\n";
    } else {
        cout << "A\n";
    }
    return 0;
}
