#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lx,ly,rx,ry,n,x,y,a,p;
    lx=0,ly=0;
    cin>>rx>>ry>>n;
    while(n--)
    {
        cin>>x>>y>>a;
        if(a==1)
            lx=max(x,lx);
        else if(a==2)
            rx=min(x,rx);
        else if(a==3)
            ly=max(y,ly);
        else if(a==4)
            ry=min(y,ry);
    }
    int area=(rx-lx)*(ry-ly);
   /* if(area>=0)
        cout<<area<<endl;
    else
        cout<<0<<endl;*/
    cout<<(max(0, rx - lx) * max(0, ry - ly))<<endl;
    return 0;
}
