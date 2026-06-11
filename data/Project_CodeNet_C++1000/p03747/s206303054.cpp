#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}
 
void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

const int maxn = 1e5+10;
const int inf = 1e9;
const lf eps = 1e-8;

int p[maxn],n,c,l,t;

signed main() {
    read(n),read(l),read(t);
    for(int i=1,x;i<=n;i++) {
        read(p[i]),read(x);x=x==2?-1:x;p[i]+=x*t;
        if(p[i]>0) c+=p[i]/l;
        else if(p[i]<0) c+=(p[i]+1)/l-1;p[i]=(p[i]%l+l)%l;
    }sort(p+1,p+n+1);c=(c%n+n)%n;
    for(int i=c+1;i<=n;i++) write(p[i]);
    for(int i=1;i<=c;i++) write(p[i]);
    return 0;
}
