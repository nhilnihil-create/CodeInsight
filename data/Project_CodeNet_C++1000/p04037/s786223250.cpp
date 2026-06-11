# include <bits/stdc++.h>
# define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn = 100010;
int read(){
    char c=getchar(); int x=0;
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return x;
}
int a[maxn];
int n;
int main(){
    n=read();
    rep(i,0,n-1)a[i]=read();
    sort(a+0,a+n);
    reverse(a+0,a+n);
    int p=0,y=0;
    for(;p+1<n&&a[p+1]>p+1;++p);
    for(;y<n&&a[y]>p;++y);
    if ((a[p]-p)&1 && (y-p)&1) puts("Second");
    else puts("First");
    return 0;
}