#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    cin >> a >> b;
    c=a*b;
    if(a==b)
    {
        cout << 0 << endl;
    }
    else if(a==0)
    {
        if(b<0)
        {
            cout << -1*b+1 << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
    else if(b==0)
    {
        if(a>0)
        {
            cout << a+1 << endl;
        }
        else
        {
            cout << -1*a << endl;
        }
    }
    else if(b>a && c>0)
    {
        cout << b-a << endl;
    }
    else if(a>b && c>0)
    {
        cout << a-b+2 << endl;
    }
    else if(c<0)
    {
        cout << abs(abs(a)-abs(b))+1 << endl;
    }
    return 0;
}
