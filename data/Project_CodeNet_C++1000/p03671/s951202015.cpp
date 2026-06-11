#include<iostream>
using namespace std;
int main()
{
    int a,b,c,m;
    cin>>a>>b>>c;

    if (a+b<a+c&&a+b<b+c)
        m=a+b;
    else if(a+c<a+b&&a+c<b+c)
        m=a+c;
    else
        m=b+c;

    cout<<m<<endl;

}

