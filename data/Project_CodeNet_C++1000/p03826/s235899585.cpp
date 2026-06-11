#include <iostream>

using namespace std;

int main()
{
    int A , B , C , D;

    cin >> A >> B >> C >> D ;

    int R1 = A * B;
    
    int R2 = C * D;

    if ( A >=1 && A <= 10^4 && B >=1 && B <= 10^4 && C >=1 && C <= 10^4 && D >=1 && D <= 10^4 ){



     if (R1 >= R2)

     cout << R1;

     else if ( R2 > R1)
     cout << R2;
    }
    return 0;
}