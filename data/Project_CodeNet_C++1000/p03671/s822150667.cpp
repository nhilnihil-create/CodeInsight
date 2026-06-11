#include<iostream>
using namespace std;
int main()
{
    int a,b,c,temp;
    cin>>a>>b>>c;
    int max=a;
    max>=b ? max=max : max=b;
    max>=c ? max=max : max=c;
    temp=(a+b+c)-max;
    cout<<temp;
    return 0;
}
