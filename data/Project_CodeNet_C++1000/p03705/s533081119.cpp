#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,n;
    long long int c,d;

    cin>>n>>a>>b;
    if(a>b)
    {
        cout<<"0";
        return 0;
    }
     if(n==1)
    {
        if(a==b)
        {
        cout<<"1";
        return 0;
        }
        else{
            cout<<"0";
            return 0;
        }
    }
    if(a==b)
    {
        cout<<"1";
        return 0;
    }
    c=(n-2)*b;
    d=(n-2)*a;
    if(d>c)
        swap(c,d);
    cout<<c-d+1;
}
