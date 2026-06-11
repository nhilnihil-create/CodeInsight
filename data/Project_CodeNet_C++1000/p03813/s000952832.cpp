#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (1 <= x && x <= 3000)
    {
        if (x <= 1199)
            cout << "ABC";
        else if (x >= 1200)
            cout << "ARC";
    }
    return 0;
}
