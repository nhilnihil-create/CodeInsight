#include <iostream>

using namespace std;

int main()
{
    int A,B ; 
    cin >> A >> B ;
    if(A == 1 && B != 1 )
    {
        cout << "Alice";
        
    }
    else if (B == 1 && A != 1 )
    {
        cout << "Bob" ;
    }
    else if (A == B)
    {
        cout << "Draw" ;
    }
    else if (A > B && B != 1)
    {
        cout << "Alice" ;
    }   
    else if (B > A && A != 1)
    {
        cout << "Bob" ;
    }   
    return 0;
}
