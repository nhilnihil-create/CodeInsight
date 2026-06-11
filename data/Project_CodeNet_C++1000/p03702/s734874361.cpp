#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
LL m,n,t;
LL a[100005];
bool judge(LL mid)
{
    LL ans=mid;
    for(int i=0;i<t;i++)
    {
        int flag=1;
        LL c=a[i]-mid*m;
        if(c>0)
        {
            if(c%(n-m)==0)
                flag=0;
            ans-=c/(n-m)+flag;
            if(ans<0)
                return false;
        }
    }
    return true;
}
int main()
{
    cin>>t>>n>>m;
    LL maxn=0;
    for(int i=0;i<t;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    LL st=0,en=maxn;
    while(st<en)
    {
        LL mid=en+st>>1;
        if(judge(mid))
            en=mid;
        else
            st=mid+1;
    }
    cout<<en;
    return 0;
}