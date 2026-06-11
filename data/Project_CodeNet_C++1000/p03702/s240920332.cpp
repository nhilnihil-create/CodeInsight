#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a,b,c;
long long t[100001];
int ef(long long x)
{
    long long u=x;
    long long t1[100001];
    for(long long i=0; i<a; i++)
    {
        long long r;
        t1[i]=t[i]-c*x;
        if(t1[i]%(b-c)==0&&t1[i]>0)
            r=t1[i]/(b-c);
        if(t1[i]%(b-c)!=0&&t1[i]>0)
            r=t1[i]/(b-c)+1;
        if(t1[i]>0)
            u=u-r;
    }
    if(u>=0)
        return 1;
    else
        return 0;



}
int main()
{
    while(scanf("%lld %lld %lld",&a,&b,&c)!=EOF)
    {
        for(int i=0; i<a; i++)
            cin>>t[i];
        long long st,et;
        sort(t,t+a);
        st=0;
        et=1000000001;
        while(st+1<et)
        {
            int q;
            long long mid=(st+et)/2;
            q=ef(mid);
            if(q==1)
                et=mid;
            else st=mid;

        }
        cout<<et<<endl;
    }
    return 0;
}
