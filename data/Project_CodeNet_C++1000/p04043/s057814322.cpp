#include<iostream>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    if(A==5&&B==5&&C==7)
    {
        cout<<"YES";
    }
    else if(A==5&&B==7&&C==5)
    {
        cout<<"YES";
    }
    else if(A==7&&B==5&&C==5)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
