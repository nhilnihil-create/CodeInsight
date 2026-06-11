#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=110;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,m,a[N],st[N],top=0;
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        a[i]=gi();
        if(a[i]&1) st[++top]=i;
    }
    if(top>2) return puts("Impossible"),0;
    if(top) swap(a[1],a[st[1]]);
    if(top==2) swap(a[m],a[st[2]]);
    if(m==1) {
        if(a[1]==1) puts("1\n1\n1");
        else printf("%d\n2\n%d 1\n",a[1],a[1]-1);
        return 0;
    }
    for(int i=1;i<=m;i++) printf("%d ",a[i]);
    puts("");
    printf("%d\n",m-(a[1]==1));
    if(a[1]!=1) printf("%d ",a[1]-1);
    for(int i=2;i<m;i++) printf("%d ",a[i]);
    printf("%d\n",a[m]+1);
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
