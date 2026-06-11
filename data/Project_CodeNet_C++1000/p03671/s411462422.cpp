#include <iostream>

using namespace std;

int main() {
    int x, sum = 0, mx = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    cout << sum - mx << endl;
}
