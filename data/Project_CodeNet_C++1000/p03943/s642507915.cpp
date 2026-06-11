#include <iostream>
using namespace std;

int main( void )
{
    int a, b, c;
    cin >> a >> b >> c;
    if ( ( a == ( b + c ) ) || ( b == ( a + c ) ) || ( c == ( b + a ) ) )
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
