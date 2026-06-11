#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int a[7]={1,3,5,7,8,10,12};
    int b[7]={4,6,9,11};
    if(x==2) cout<<"No\n";
    else if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10)
    {
        for(int i=0;i<7;i++)
        {
            if(y==a[i])
                {cout<<"Yes\n";return 0;}

        }
        cout<<"No\n";
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(y==b[i])
            {cout<<"Yes\n";return 0;}
        }
        cout<<"No\n";
    }
}
