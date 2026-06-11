#include <iostream>

using namespace std;

int main()
{
    long a,b,c,d ; 
    long long F , G;

    cin >> a >> b>>c >>d;
    F = a * b ; 
    G = c*d ;
    if (F >= G )
    {
        cout << F ;
    }
    else if (F <= G )
    {
        cout << G ;
    }

    return 0;
}
