#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[] = { 1, 3, 5, 7, 8, 10, 12 };
    int b[] = { 4, 6, 9, 11 };
    int x, y;
    cin >> x >> y;
    int t = 0;
    for (int i = 0; i < 7; i++)
    {
        if (a[i] == x) t++;
        if (a[i] == y) t++;
        if (t == 2)
        {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (b[i] == x) t++;
        if (b[i] == y) t++;
        if( t == 2 )
        {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    if (x == 2 && y == 2) {
        cout << "Yes" << '\n'; return 0;
    }
    else cout << "No" << '\n';
   
}

