#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int common = min(b, d) - max(a, c);
    common = (common >= 0) ? common : 0;
    cout << common << endl;
    return EXIT_SUCCESS;
}