#include<iostream>
using namespace std;
int main ()
{
    string a,b,c;
    int temp;
    char n;
    cin>>a>>b>>c;
    n=a[0];
    temp=int(n);
    temp=temp-32;
    n=char(temp);
    cout<<n;

    n=b[0];
    temp=int(n);
    temp=temp-32;
    n=char(temp);
    cout<<n;

    n=c[0];
    temp=int(n);
    temp=temp-32;
    n=char(temp);
    cout<<n;
    return 0;
}
