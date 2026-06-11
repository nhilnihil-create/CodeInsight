#include<bits/stdc++.h>
#include<algorithm>
//#include<string.h>
using namespace std;
int main()
{
    int a[]={1,3,5,7,8,10,12};
    int b[]={4,6,9,11};
    int c[]={2};
    int x,y,m=0,n=0;
    cin>>x>>y;
    for(int i=0; i<7; i++)
    {
        if(a[i]==x || a[i]==y)
            m++;
    }
    for(int j=0; j<4; j++)
    {
        if(b[j]==x || b[j]==y)
            n++;
    }
    (m==2 || n==2)?cout<<"Yes":cout<<"No";}
