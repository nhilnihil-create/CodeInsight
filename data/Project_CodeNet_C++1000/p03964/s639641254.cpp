#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a=1,b=1;
    for(int i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        long long c1=(a+x-1)/x;
        long long c2=(b+y-1)/y;
        long long c=max(c1,c2);
        a=x*c;
        b=y*c;
    }
    cout<<a+b<<endl;
    return 0;
}
