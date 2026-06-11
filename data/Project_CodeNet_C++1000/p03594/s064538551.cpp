#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
/*
转切比雪夫距离就可以做了。 
直接构造。

左上角R,左下角Y,右上角G,右下角B。 
填充即可。 
*/
#ifdef Fading
#define gc getchar
#endif
#ifndef Fading
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
#endif
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
int n,m;
const int mx=1100;
char S[4]={'R','Y','G','B'};
signed main(){
    n=read(),m=read();
    int D=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
        	int tm1=(((i-j+n+m)/D)%2+2)%2;
        	int tm2=(((i+j+n+m)/D)%2+2)%2;
            printf("%c",S[2*tm1+tm2]);
        }
        printf("\n");
    }
    return 0;
}
