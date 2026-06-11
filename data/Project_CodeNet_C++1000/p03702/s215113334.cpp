#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+10;
ll heal[maxn];
ll A,B;
int N;
bool check(ll x)
{
    ll cnt=0;
    ll gap;
    //cout<<x<<"!"<<endl;
    for(int i=N-1;i>=0;i--)
    {
        //cout<<heal[i]<<' '<<cnt<<endl;
        if(x*B>=heal[i])return true;
        gap=heal[i]-x*B;
       //cout<<"g"<<gap<<endl;
        cnt+=gap/A;
        if(gap%A)cnt++;
        //cout<<cnt<<endl;
        if(cnt>x)return false;
    }
    return true;
}
int main()
{
    cin>>N>>A>>B;
    A-=B;
    for(int i=0;i<N;i++)cin>>heal[i];
    sort(heal,heal+N);
    ll l,r,mid;
    l=1;r=N*heal[N-1]/B+1;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
