#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long l,r,mid;
long long e(long long x)
{
    long long ans=1;
    for(int i=1;i<x;++i)
        ans*=10;
    return ans;
}
bool check(long long x)
{
    char ch='0';
    cout<<'?'<<' '<<x<<endl;
    while(ch!='Y'&&ch!='N') cin>>ch;
    if(ch=='Y') return true;
    else return false;
   /*
    const long long ans=369;
    const string s=to_string(ans);
   string xs=to_string(x);
   if(ans<=x&&s<=xs) return true;
   if(ans>x&&s>xs) return true;
   return false;
   */
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i=1;i<=11;i++)
    {
        if(!check(e(i)))
        {
            l=e(i-1);r=e(i)-1;
            break;
        }
    }
    if(l==0)
    {
        for(int i=1;i<=11;i++)
        if(check(e(i+1)-1))
        {
            cout<<"! "<<e(i)<<endl;
            return 0;
        }
    }
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(10*mid))
            r=mid-1;
        else
            l=mid+1;
    }
    cout<<"! "<<l<<endl;
    return 0;
}