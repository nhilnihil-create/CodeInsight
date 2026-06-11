#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w,h,n;
    cin>>w>>h>>n;
    int minx=0,maxx=w,miny=0,maxy=h;
    for(int i=0;i<n;i++)
    {
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1)
        {
            minx=max(minx,x);
        }
        if(a==2)
        {
            maxx=min(maxx,x);
        }
        if(a==3)
        {
            miny=max(miny,y);
        }
        if(a==4)
        {
            maxy=min(maxy,y);
        }
    }
    int x=(maxx-minx);
    int y=(maxy-miny);
    int area=x*y;
    if(x<0 || y<0)
    {
        area=0;
    }
    cout<<area;
  	return 0;
}





