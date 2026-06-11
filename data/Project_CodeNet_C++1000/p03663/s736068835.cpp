#include <bits/stdc++.h>
using namespace std;

int64_t res=0,len,mul[15];

void FindLen()
{
    mul[0]=1;
    for(int i=1;i<=10;i++)
        mul[i]=mul[i-1]*10LL;
    char c;
    int rs=1,l=2,r=10;
    bool check=false;
    while(l<=r)
    {
        int mid=(l+r)/2;
        cout<<"? "<<mul[mid-1]<<"\n";
        fflush(stdout);
        cin>>c;
        if(c=='Y')
        {
            rs=mid;
            l=mid+1;
        }
        else
        {
            check=true;
            r=mid-1;
        }
    }
    if(check==true)
        len=rs;
    else
    {
        l=1,r=9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            cout<<"? "<<mul[mid]-1<<"\n";
            fflush(stdout);
            cin>>c;
            if(c=='Y')
            {
                rs=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        len=rs;
    }
}

int Binary(int l,int r)
{
    char c;
    int rs;
    while(l<=r)
    {
        int mid=(l+r)/2;
        cout<<"? "<<res*10+mid<<"\n";
        fflush(stdout);
        cin>>c;
        if(c=='Y')
        {
            rs=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return rs;
}

int main()
{
    FindLen();
    for(int i=1;i<=len-1;i++)
    {
        int tmp;
        if(i==1)
            tmp=Binary(1,9);
        else
            tmp=Binary(0,9);
        res=res*10+tmp;
    }
    int tt=0;
    if(len==1)
        tt=1;
    for(int i=tt;i<=9;i++)
    {
        char c;
        cout<<"? "<<res*100+i*10<<"\n";
        fflush(stdout);
        cin>>c;
        if(c=='Y')
        {
            res=res*10+i;
            break;
        }
    }
    cout<<"! "<<res;
}
