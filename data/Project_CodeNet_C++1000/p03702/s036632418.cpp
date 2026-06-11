#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll sp[maxn];
ll ri,le;
ll a,b,n;
bool check(ll x)
{
    ll how=0;
    for(int i=1;i<=n;++i)
    {
        if(sp[i]>x*b)
        {
            ll kk=sp[i]-x*b;
            if(kk%(a-b)==0)
            {
                how+=(kk/(a-b));
            }
            else how+=(kk/(a-b))+1;
        }
    }
    if(how>x)return 1;
    else return 0;
}
int main()
{
    ri=0;
    le=1;
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i)
    {
        cin>>sp[i];
    }
    sort(sp+1,sp+1+n);
    for(int i=1;i<=n;++i)
    {
        ri=ri+sp[i]/b+1;
    }
    ll mid;
    while(le<ri)
    {
        mid=(le+ri)/2;
        if(check(mid)==1)
        {
            le=mid+1;
        }
        else ri=mid;
    }
    cout<<le<<endl;
    return 0;
}
