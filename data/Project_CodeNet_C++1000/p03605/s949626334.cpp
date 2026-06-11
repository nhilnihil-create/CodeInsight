#include <iostream>
#include <cmath>
using namespace std;

int main( void )
{
    char n[ 3 ];
    cin >> n;
    if ( n[ 0 ] == '9' || n[ 1 ] == '9' )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
