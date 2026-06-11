#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,x,c,i,j;
    cin>>a>>b>>x;
    if(a%x==0)
        c=(a/x)-1;
        //cout<<c<<endl;
    else
        c=(a/x);
         //cout<<c<<endl;

    cout<<(b/x)-c<<endl;

    return 0;
}