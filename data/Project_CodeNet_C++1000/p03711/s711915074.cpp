#include <iostream>
#include <cstring>
using namespace std;

int main( void )
{
    int x, y;
    cin >> x >> y;
    if ( x == 2 || y == 2 )
    {
        cout << "No";
    }
    else if ( x == 4 && ( y == 6 || y == 9 || y == 11 ) )
    {
        cout << "Yes";
    }
    else if ( x == 6 && ( y == 9 || y == 11 ) )
    {
        cout << "Yes";
    }
    else if ( x == 9 && ( y == 11 ) )
    {
        cout << "Yes";
    }
    else if ( x == 11 )
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    return 0;
}
