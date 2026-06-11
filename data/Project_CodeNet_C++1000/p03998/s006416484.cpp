#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,c;
    char ch='a';
    cin>>a>>b>>c;
    while(true)
    {

        if(ch=='a')
        {
            if(a.empty())   {cout<<"A"; return 0;}
            ch=a[0];
            a.erase(0,1);
        }
        else if(ch=='b')
        {
            if(b.empty())   {cout<<"B"; return 0;}
            ch=b[0];
            b.erase(0,1);
        }
        else if(ch=='c')
        {
            if(c.empty())   {cout<<"C"; return 0;}
            ch=c[0];
            c.erase(0,1);
        }
    }
    return 0;
}
