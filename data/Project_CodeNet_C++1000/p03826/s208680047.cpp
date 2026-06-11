#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s1 = a * b, s2 = c * d;
    if (s1 >= s2)
        cout << s1 << endl;
    else
        cout << s2 << endl;
    return 0;
}