#include <iostream>
using namespace std;

int W, a, b;

int main() {
    cin >> W >> a >> b;

    if (b > a + W) cout << b - (a + W) << endl;
    if (b <= a + W && b + W >= a) cout << "0" << endl;
    if (b + W < a) cout << a - (b + W) << endl;
    return 0;
}