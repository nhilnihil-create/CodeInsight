#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;
    if(a==1)
    {
        a=100;
    }
    if(b==1)
    {
        b=100;
    }
    if(a>b)
    {
        cout<<"Alice\n";
    }
    else if(a<b)
    {
        cout<<"Bob\n";
    }
    else
    {
        cout<<"Draw\n";
    }
    return 0;
}
