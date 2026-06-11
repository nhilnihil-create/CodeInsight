#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i;
    if (n == 0) {
        cout << 0;
        return 0;
    } else if (n == 1) {
        cout << 1;
        return 0;
    }
    for (i = 2; i * (i + 1) / 2 < n; ++i);
    cout << i;
    return 0;
}
