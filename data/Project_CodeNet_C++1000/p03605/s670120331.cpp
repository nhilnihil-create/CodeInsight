#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    a=n%10;
    b=n/10;
    if(a==9 || b==9)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

