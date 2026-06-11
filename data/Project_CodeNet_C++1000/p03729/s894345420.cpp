#include <iostream>
#include <string>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;
    if (a[a.length() - 1] == b[0] && b[b.length() - 1] == c[0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
