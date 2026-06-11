#include <iostream>

using namespace std;

int main()
{
    int n , result =0 ;
    cin >> n;

    for(int i=1 ; i<n+1; i++)
        result += i ;

    cout << result ;
    return 0;
}
