#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
const int ma=1e6;
int a[ma],t[ma];
string s;
int ne(int p2,int p,int t)
{
    if(p)t^=1;
    if(t==0)return p2;
    return p2^1;
}
main()
{
    int n;
    cin>>n;
    cin>>s;
    rep(i,0,n)
    {
        if(s[i]=='o')t[i]=0;
        else t[i]=1;
    }
    rep(i1,0,2)
    {
        rep(i2,0,2)
        {
            a[0]=i1,a[1]=i2;
            rep(i,2,n)a[i]=ne(a[i-2],a[i-1],t[i-1]);
            if(ne(a[n-2],a[n-1],t[n-1])!=a[0])continue;
            if(ne(a[n-1],a[  0],t[  0])!=a[1])continue;
            rep(i,0,n)
            {
                if(a[i]==0)printf("S");
                else printf("W");
            }
            printf("\n");
            return 0;
        }
    }
    cout<<-1<<endl;
}