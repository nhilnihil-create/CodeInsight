#include<string.h>
#include<stdio.h>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,d;
int a[2111][2111];
int B=1010;
char ans[511][511];
int main()
{
    int i,j,k;
    
    cin>>n>>m>>d;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            int xx,yy;
            xx=i+j+B;yy=i-j+B;
            xx/=d;yy/=d;
            if(xx%2==0 && yy%2==0)
            {
                ans[i][j]='R';
            }
            else if(xx%2==0 && yy%2==1)
            {
                ans[i][j]='Y';
            }
            else if(xx%2==1 && yy%2==0)
            {
                ans[i][j]='G';
            }
            else
            {
                ans[i][j]='B';
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
