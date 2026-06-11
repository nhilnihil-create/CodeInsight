#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include <string>
#include <cstring>
#include <cstdio>
#include<stack>
using namespace std;
struct po
{
    int a,num;
};
bool cmp(po x,po y)
{
    return x.a<y.a;
}
int main()
{
    struct po  s[100008]= {0};
    int i,j,t;
    int n;
    cin>>n>>t;
    t/=2;
    for(i=0; i<n; i++)cin>>s[i].a;
    int m=-1,x=s[0].a;
    for(i=0; i<n; i++)
    {
        s[i].num=i;
        if(s[i].a>=x)m=max(s[i].a-x,m);
        else x=s[i].a;
    }
    sort(s,s+n,cmp);
    int re=0,mii;
    for(i=0;i<n;i++)
    {
        int l=0,r=n-1;
        while(l<=r)
        {
            int mi=(l+r)/2;
            mii=mi;
            if(s[i].a+m>s[mi].a)
            {
                l=mi+1;
            }
            else if(s[i].a+m<s[mi].a)r=mi-1;
            else break;
        }
        if(s[mii].a==s[i].a+m&&s[mii].num>s[i].num)
        {
            re++;
        }
        else if(s[mii].a==s[i].a+m&&s[mii].num<s[i].num)
        {
            int tol=mii,tor=mii;
            while(s[tol].a==s[i].a+m)
            {
                if(s[tol].num>s[i].num)
                {
                    re++;
                    goto p;
                }
                tol--;
            }
            while(s[tor].a==s[i].a+m)
            {
                if(s[tor].num>s[i].num)
                {
                    re++;
                    goto p;
                }
                tor--;
            }
        }
        p: ;
    }
    cout<<re<<endl;
    return 0;
}
