#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[100005];
ll sum=0;
void print(int x)
{
    if(!x)puts("First");
    else puts("Second");
}
int gcd(int x,int y)
{
    if(!y)return x;
    return gcd(y,x%y);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);sum+=a[i];
    }
    int now=0;
    while(1)
    {
        if(n%2!=sum%2)return print(now),0;
        int id=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==1&&a[i]!=1)
            {
                if(!id)id=i;
                else return print(now^1),0;
            }
        }
        if(!id)return print(now^1),0;
        a[id]--;
        int g=a[1];for(int i=2;i<=n;i++)g=gcd(g,a[i]);
        sum=0;
        for(int i=1;i<=n;i++)a[i]/=g,sum+=a[i];
        now^=1;
    }
    return 0;
}
