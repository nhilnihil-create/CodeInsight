#include <iostream>

using namespace std;

int main()
{
    int a , b ,c,d ,A1 ,A2 ;
    cin >> a>>b>>c>>d ;
    A1=a*b ;
    A2=c*d ;
    if (A1>A2)
    cout << A1 ;
    else if ( A1<A2)
    cout << A2 ;
    else if ( A1==A2)
    cout << A1 ;


    return 0;
}
