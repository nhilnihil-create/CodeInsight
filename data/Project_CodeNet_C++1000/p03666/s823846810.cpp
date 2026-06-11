#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a,b,c,d,r,w;
double e,h=0.5,m,l;
int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    e+=c+d;
    e/=2;
    h=e-c;
    m=h*(n-1);
    r=abs(a-b);
    if(r>(n-1)*e+m){printf("NO\n");return 0;}
    w=(int)(r/e);
    l=r-e*w;
    if(n%2)
        if(w%2)
		{
            l=e-l;
            if(l<=m){printf("YES\n");return 0;}
            else{printf("NO\n");return 0;}
        }
        else
            if(l<=m){printf("YES\n");return 0;}
            else{printf("NO\n");return 0;}
    else
        if(w%2)
            if(l<=m){printf("YES\n");return 0;}
            else{printf("NO\n");return 0;}
        else
		{
            l=e-l;
            if(l<=m){printf("YES\n");return 0;}
            else{printf("NO\n");return 0;}
        }
    return 0;
}