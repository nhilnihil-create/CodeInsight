#include<bits/stdc++.h>
using namespace std;
char a[100009];
int b[100009];
int n;
int f(int s1,int s2)
{
    b[1]=s1;
    b[2]=s2;
    for(int i=3; i<=n; i++)
    {
        if(a[i-1]=='o')
        {
            if(b[i-1]==1)
            {
                b[i]=b[i-2]^1;
            }
            if(b[i-1]==0)
            {
                b[i]=b[i-2];
            }
        }
        else if(a[i-1]=='x')
        {
            if(b[i-1]==0)
            {
                b[i]=b[i-2]^1;
            }
            if(b[i-1]==1)
            {
                b[i]=b[i-2];
            }
        }
    }
    if(b[1]==b[n-1]&&b[n]==b[2])
    {
        if(b[n]==0&&a[n]=='o'&&b[1]==0&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='x'&&b[1]==0&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='x'&&b[1]==1&&a[1]=='x')
        {
            return 1;
        }
        else if(b[n]==0&&a[n]=='o'&&b[1]==1&&a[1]=='x')
        {
            return 1;
        }
    }
    else if(b[1]!=b[n-1]&&b[n]==b[2])
    {
        if(b[n]==0&&a[n]=='x'&&b[1]==0&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='o'&&b[1]==1&&a[1]=='x')
        {
            return 1;
        }
        else if(b[n]==0&&a[n]=='x'&&b[1]==1&&a[1]=='x')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='o'&&b[1]==0&&a[1]=='o')
        {
            return 1;
        }
    }
    else if(b[1]==b[n-1]&&b[n]!=b[2])
    {
        if(b[n]==0&&a[n]=='o'&&b[1]==0&&a[1]=='x')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='x'&&b[1]==1&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==0&&a[n]=='o'&&b[1]==1&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='x'&&b[1]==0&&a[1]=='x')
        {
            return 1;
        }
    }
    else if(b[1]!=b[n-1]&&b[n]!=b[2])
    {
        if(b[n]==0&&a[n]=='x'&&b[1]==0&&a[1]=='x')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='o'&&b[1]==1&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==0&&a[n]=='x'&&b[1]==1&&a[1]=='o')
        {
            return 1;
        }
        else if(b[n]==1&&a[n]=='o'&&b[1]==0&&a[1]=='x')
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<=1; i++)
    {
        for(int j=0; j<=1; j++)
        {
            if(f(i,j))
            {
                for(int u=1; u<=n; u++)
                {
                    if(b[u]==1)
                    {
                        cout<<"W";
                    }
                    else
                    {
                        cout<<"S";
                    }
                }
                cout<<endl;
                return 0;
            }

        }
    }
    cout<<"-1"<<endl;
}
