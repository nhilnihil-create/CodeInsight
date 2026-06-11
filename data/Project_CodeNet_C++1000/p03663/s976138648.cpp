#include<bits/stdc++.h>
#define pp pair<int,int>
#define MZ 1000000007
#define Pi acos(-1)
#define pq priority_queue

using namespace std;

int num[15];
int ans[15];
char c[6];

int main()
{
    int len,l,r,mid;
    l=1,r=10;
    num[1]=1;
    for(int i=2;i<=10;i++)
        num[i]=num[i-1]*10;
    while(l!=r)
    {
        mid=(l+r+1)/2;
        cout<<"? "<<num[mid];
        cout<<endl;
        fflush(stdout);
        cin>>c;
        if(c[0]=='Y')
            l=mid;
        else
            r=mid-1;
    }
    len=l;
    if(len==10)
    {
        cout<<"? 999999999"<<endl;
        fflush(stdout);
        cin>>c;
        if(c[0]=='Y')
        {
            for(int i=1;i<=9;i++)
            {
                cout<<"? ";
                for(int j=1;j<=i;j++)
                    cout<<9;
                cout<<endl;
                fflush(stdout);
                cin>>c;
                if(c[0]=='Y')
                {
                    cout<<"! 1";
                    for(int j=1;j<i;j++)
                        cout<<0;
                    cout<<endl;
                    fflush(stdout);
                    return 0;
                }
            }
        }
        else
            cout<<"! 1000000000"<<endl;
        return 0;
    }
    for(int i=1;i<len;i++)
    {
        if(i==1)
            l=1;
        else
            l=0;
        r=9;
        while(l!=r)
        {
            mid=(l+r+1)/2;
            cout<<"? ";
            for(int j=1;j<len;j++)
            {
                if(j<i)
                    cout<<ans[j];
                if(j==i)
                    cout<<mid;
                if(j>i)
                    cout<<0;
            }
            cout<<endl;
            fflush(stdout);
            cin>>c;
            if(c[0]=='Y')
                l=mid;
            else
                r=mid-1;
        }
        ans[i]=l;
    }
    for(int i=1;i<=9;i++)
    {
        cout<<"? ";
        for(int j=1;j<len;j++)
            cout<<ans[j];
        cout<<i;
        cout<<0;
        cout<<endl;
        fflush(stdout);
        cin>>c;
        if(c[0]=='Y')
        {
            ans[len]=i;
            break;
        }
    }
    cout<<"! ";
    for(int i=1;i<=len;i++)
        cout<<ans[i];
    cout<<endl;
    fflush(stdout);
    return 0;
}
