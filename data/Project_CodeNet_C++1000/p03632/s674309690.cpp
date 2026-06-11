#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=c)
    {
        if(b<=c)
        {
            cout<<"0";
        }
        else
        {
            if(b>=d)
            {
                cout<<(d-c);
            }
            else
            {
                cout<<(b-c);
            }
        }
    }
    else if(a>=d)
    {
        cout<<"0";
    }
    else
    {
        if(b<=d)
        {
            cout<<(b-a);
        }
        else
        {
            cout<<(d-a);
        }
    }
    return 0;
}

