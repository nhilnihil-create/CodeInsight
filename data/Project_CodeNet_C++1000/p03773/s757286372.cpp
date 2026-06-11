#include <iostream>

using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;
    int sum;
    if(A+B>=24)
    {
        cout<<((A+B)%24);
    }
    else cout<<A+B;
    return 0;
}
