#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,d=0;
    string c;
    cin>>a>>c>>b;
    if(c[0]=='+')
    {
        d=a+b;
    }
    else
    {
        d=a-b;
    }
    cout<<d<<endl;
    return 0;
}
