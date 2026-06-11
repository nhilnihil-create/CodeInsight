#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[]={4,6,9,11};int x,z;cin>>x>>z;
    if(x==2||z==2)
    cout<<"No\n";
    else
    {
        bool f1=false,f2=false;
        for(int i=0;i<4;++i)
        {
            if(a[i]==x)
            f1=true;
            if(a[i]==z)
            f2=true;
        }
        if(f1==f2)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }

    return 0;
}
