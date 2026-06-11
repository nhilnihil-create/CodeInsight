#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include<iostream>
#include<vector>
#define MAXN 1000100
using namespace std;
typedef long long ll;
///设一个怪物炸y次,总共炸x次则
/// a[i]<=A*y+(x-y)*B 即 x*B+(A-B)y
/// 所以 y>=(a[i]-x*B)/(A-B) (向上取整) 66666
ll a[MAXN];
ll n,A,B;
bool judge(ll x)
{
    ll sub=x*B;
    ll div=A-B;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]>sub)
        {
            ll temp=(a[i]-sub)/div;
        if((a[i]-sub)%div>0)
            sum+=temp+1;
        else sum+=temp;
        }
        
    }
   // cout<<x<<"     "<<sum<<endl;
    if(sum<=x)return true;
    return false;
}
int main()
{
    cin>>n>>A>>B;
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        cnt+=a[i]/B+1;
    }
    ll l=1,r=cnt;
    while(l<=r)
    {
       // cout<<l<<endl;
        ll mid=(l+r)>>1;
        if(judge(mid))
            r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
}





