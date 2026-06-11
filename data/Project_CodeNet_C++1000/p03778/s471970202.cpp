#include<iostream>
using namespace std;

int main() {
    int W, a, b; cin >> W >> a >> b;
    if (a + W < b || b + W < a) {
        cout << min(abs(b - a - W), abs(a - b - W)) << endl;
    } else {
        cout << 0 << endl;
    }
}
