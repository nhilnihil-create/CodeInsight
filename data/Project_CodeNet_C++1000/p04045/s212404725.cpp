#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int d[10];
    memset(d,0,sizeof(d));
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        d[x]=1;
    }
    for(int i=n;i<=100000;i++)
    {
        bool p=true;
        int a[10];
        int temp=i;
        memset(a,0,sizeof(a));
        while(temp>0)
        {
            int t=temp%10;
            temp/=10;
            a[t]++;
        }
        for(int j=0;j<=9;j++)
        {
            if(a[j]>0 && d[j]>0)
            {
                p=false;
                break;
            }
        }
        if(p)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}





