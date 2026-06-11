#include <iostream>
using namespace std;

int main( void )
{
    int n;
    cin >> n;
    if ( ( n - ( n / 100 ) ) % 10 == 0 )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
