#include <iostream>
using namespace std;
long long a,b;
string x;
int main()
{
    cin>>a>>x>>b;
    if (x=="+")
    {
        cout<<a+b<<endl;
    }
    else if (x=="-")
    {
        cout<<a-b<<endl;
    }
}