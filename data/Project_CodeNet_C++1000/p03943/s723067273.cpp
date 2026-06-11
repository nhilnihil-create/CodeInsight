#include <iostream>
using namespace std;

int main( void )
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = ( a + b + c ) / 2;
    int mod = ( a + b + c ) % 2;
    if ( mod == 0 )
    {
        if ( (ans == a) || (ans == b) || (ans == c) )
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
