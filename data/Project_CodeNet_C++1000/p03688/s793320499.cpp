#include<bits/stdc++.h>
using namespace std;
int a[1000000],n;
bool same(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[0]) return false;
    }
    return true;
}
bool dekhao(int *a,int n,int total,int mn,int mx)
{
    int col[total],now=n;
    memset(col,0,sizeof col);
    for(int i=0;i<total;i++)
    {
        if(a[i]==mn)
        {
            col[i]++;
            now--;
        }
        else
        {
            int baki=total-i-1;
             baki=baki*2;
            col[i]=now-baki;
            now-=col[i];
            if(col[i]<=0) return false;
        }
    }
    int prev=0,cs=0;
    for(int i=0;i<total;i++)
    {
        cs+=col[i];
        for(int j=prev;j<cs;j++)
        {
            if(a[j]!=(total-1)+(col[i]>1))
                return false;
        }
        prev=cs;

    }
    return (now==0)&&true;
}


main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int mn=a[0],mx=a[n-1];
    if(mx-mn>1)
    {
        cout<<"No";return 0;
    }

    if(!same(a,n))
    {
        cout<<((dekhao(a,n,mx,mn,mx))?"Yes":"No");
        return 0;
    }
    else
    {
        if(n==mn+1)
        {
            cout<<"Yes";return 0;
        }
        else if(n<=mn)
        {
            cout<<"No";
            return 0;
        }
        else if(n>=2*mn)
        {
            cout<<"Yes";return 0;
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }

}
