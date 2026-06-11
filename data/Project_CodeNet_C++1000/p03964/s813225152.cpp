#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; long long total=0;
    cin>>n; long long pa,pb;
    for(int i=0; i<n; i++)
    {
        long long a,b;
        cin>>a>>b;
        if(total==0)
        {
            total+=a+b;
            pa=a; pb=b;
        }
        else
        {
            long long c=a,d=b;
            long long x=pa/a; if(pa%a!=0) x++;
            long long y=pb/b; if(pb%b!=0) y++;
            long long z=max(x,y);
            a=z*a; b=z*b;
            pa=a; pb=b;
        }
    }
    cout<<pa+pb<<endl;
    return 0;
}
