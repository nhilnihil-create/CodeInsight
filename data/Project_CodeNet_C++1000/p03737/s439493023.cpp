#include <iostream>
using namespace std;

int main( void )
{
    char a[ 11 ];
    char b[ 11 ];
    char c[ 11 ];
    cin >> a >> b >> c;

    cout << (char)(a[ 0 ] - 32) << (char)(b[ 0 ] - 32) << (char)(c[ 0 ] - 32) << endl;
    return 0;
}
