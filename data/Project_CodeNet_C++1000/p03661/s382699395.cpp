#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,e,f,i;
    cin>>a;
    long long int ar[a];
    long long int sum=0;
    for(i=0;i<a;i++)
    {
        cin>>ar[i];
        sum+=ar[i];

    }
    c=0;
    d=0;
    for(i=0;i<a-1;i++)
    {
        c+=ar[i];
        d=sum-c;
        f=abs(c-d);
    e=min(e,f);

    }
    cout<<e<<endl;
    return 0;
}

