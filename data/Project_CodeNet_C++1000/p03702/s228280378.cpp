#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int tail[100010];
bool pan(long long x)
{
    long long sum = 0;
    for(int i = 1;i<=n;++i)
    {
        long long t = (long long)tail[i]-x*b;
        if(t>0)
        {
            sum+=(long long)ceil(t*1.0/(a-b));
            if(sum>x||sum<0)
                return false;
        }
    }
    return true;
}
int main()
{
        scanf("%d%d%d",&n,&a,&b);
        int imax = 0;
        for(int i = 1;i<=n;++i)
        {
            scanf("%d",&tail[i]);
            imax = max(imax,tail[i]);
        }
        long long l = 0,r = imax;
        long long mid;
        while(l<r)
        {

            mid = l+r>>1;
            //cout<<"l: "<<l<<" r: "<<r<<" mid: "<<mid<<'\n';
            if(pan(mid)) r = mid;
            else l = mid + 1;
        }
        cout<<r<<'\n';
}
