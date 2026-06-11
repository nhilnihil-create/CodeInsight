#include<iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>>a;
    cin>>b;
    cin>>c;
    d=a+b;
    e=b+c;
    f=a+c;

    if((a>b&&a>c)||(c==b&&c<a)||(a==b&&a>c))
    {

        cout<<e<<endl;
    }
    else if((b>c&&b>a)||(a==c&&a<b)||(b==c&&b>a))
    {
        cout<<f<<endl;
    }
    else if((c>a&&c>b)||(a==b&&a<c)||(a==c&&c>b))
    {
        cout<<a+b<<endl;
    }
    else if(a==b&&a==c)
    {
        cout<<a+b<<endl;
    }


    return 0;
}