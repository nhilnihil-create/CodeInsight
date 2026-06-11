#include <iostream>
using namespace std;

int main( void )
{
    char s[ 19 ];
    cin >> s;
    for ( int i = 0; i < 19; i++ )
    {
        if ( i == 5 || i == 13 )
        {
            cout << ' ' << flush;
        }
        else
        {
            cout << s[ i ];
        }
    }

    return 0;
}
