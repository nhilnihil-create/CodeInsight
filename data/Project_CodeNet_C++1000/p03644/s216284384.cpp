#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int a=1;
    int b=1;

    for(b=1;b<=n;b+=a)
    {
        if(b/a%2==0)
        {
            a*=2;
        }
    }

    b-=a;

    cout<<b<<"\n";

    return 0;
}
