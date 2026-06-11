#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int a,b,c,ans=0;
    cin>>a>>b>>c;
    while(a%2==0&&b%2==0&&c%2==0)
    {
        if(a==b&&b==c)
        {
        cout<<-1;
        return 0;
        }
        ++ans;
        long int ta,tb,tc;
        ta=(b/2)+(c/2);
        tb=(a/2)+(c/2);
        tc=(b/2)+(a/2);
        a=ta;
        b=tb;
        c=tc;
    }
    cout<<ans;
    return 0;
}

