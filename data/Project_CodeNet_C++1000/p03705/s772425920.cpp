#include<bits/stdc++.h>
using namespace std;
int n,a,b;
inline int read(){
    int res=0,f_f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f_f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)-'0'+ch,ch=getchar();
    return res*f_f;
}
int main(){
    n=read(),a=read(),b=read();
    if(a>b) printf("0\n");
    else if(n==1&&a!=b) printf("0\n");
    else printf("%lld\n",1ll*(n-1)*b+a-1ll*(n-1)*a-b+1);
    return 0;
}