#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int res = a + b;
    if (res > 9) cout << "error"; else cout << res;
    cout << endl;
}
