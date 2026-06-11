#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int a[7]={1,3,5,7,8,10,12},b[1]={2},c[4]={4,6,9,11};
    int x,y;
    int flag1=0,flag2=0;
    cin>>x>>y;

    if(x==2 || y==2)
    {
        printf("No");
        return 0;
    }
    for(int i=0;i<7;i++)
    {
        if(a[i]==x)
        {
            flag1=1;
        }

        if(a[i]==y)
        {
            flag2=1;
        }
    }

    if(flag1==flag2)
    {
        printf("Yes");
        return 0;
    }

flag1=0;flag2=0;
     for(int i=0;i<4;i++)
    {
        if(c[i]==x)
        {
            flag1=1;
        }

        if(c[i]==y)
        {
            flag2=1;
        }
    }

    if(flag1==flag2)
    {
        printf("Yes");
        return 0;
    }



    printf("No");

    return 0;






}