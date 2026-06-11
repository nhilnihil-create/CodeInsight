#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long gcd(long x, long y)
{    if (y == 0)
        return x;
    return gcd(y, x % y);}
long long lcm(long x, long y){ return x * y / gcd(x, y);}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}


int main()
{
    int N,M,f[100010]={},b[100010]={},x,y,ans=0;
    cin>>N>>M;
    f[1]=1;

    for(int i=1;i<=N;i++){
        b[i]=1;
    }

    for(int i=1;i<=M;i++){
        cin>>x>>y;

        if(f[x]==1)f[y]=1;
        b[x]--;
        if(b[x]==0)f[x]=0;
        b[y]++;
    }

    for(int i=1;i<=N;i++){
        if(f[i]==1&&b[i]>0)ans++;
    }

    cout<<ans<<endl;

    return 0;
}