#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b<a+c && a+b<b+c)
        cout<<a+b<<endl;
    else if(b+c<a+c)
        cout<<b+c<<endl;
    else
        cout<<a+c<<endl;
    return 0;
}