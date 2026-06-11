#include <iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int n=a.length();
    if(n%2==0)
    {
        if(a[0]==a[n-1])
            cout<<"First";
        else
            cout<<"Second";
    }
    else
    {
        if(a[0]==a[n-1])
            cout<<"Second";
        else
            cout<<"First";
    }
}