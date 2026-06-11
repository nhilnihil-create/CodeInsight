#include <iostream>

using namespace std;

int main()
{
    int x, y, z, n , a1, a2;
    cin >> x >> y >> z >> n;

    a1 = x * y;
    a2 = z * n;

    if (a1 >= a2)
        cout << a1;
    else
        cout << a2;
    return 0;
}

