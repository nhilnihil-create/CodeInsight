#include <iostream>

using namespace std;

int main() {
    int x, a, b;
    cin >> x >> a >> b;

    if (max(x, a) - min(x, a) < max(x, b) - min(x, b)) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
}