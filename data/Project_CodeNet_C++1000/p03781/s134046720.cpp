#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int x;
    cin >> x;

    int t = 0;
    while (x > 0) {
        t += 1;
        x -= t;
    }
    cout << t << '\n';

    return 0;
}
