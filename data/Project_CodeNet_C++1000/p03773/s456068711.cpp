#include <iostream>

using namespace std;

int main()
{
    int A,B,C ; 
    cin >> A >> B ;
    C=A+B ;
    if(C <= 23)
    {
        cout << C ;
        
    }
    else 
    {
        cout << (A+B)-24 ;
    }
    return 0;
}