#include <iostream>
using namespace std;

int main (void) {
    int x, t;
    cin >> x >> t;

    if(t < x) {
        x = x - t;
        cout << x << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}
