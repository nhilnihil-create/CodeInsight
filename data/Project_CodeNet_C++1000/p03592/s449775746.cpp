#include<iostream>
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
using namespace std;
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}
inline void Yeah(){puts("Yes");exit(0);}
int main(){ 
    int n=read(),m=read(),k=read();
    for(int i=1;i<=n;++i){int kk=(k-i*m),a=n-i-i;if(!kk||a&&(kk>>31&1)==(a>>31&1)&&kk%a==0 && kk/a<=m)Yeah();}
    puts("No");
    return 0;
}