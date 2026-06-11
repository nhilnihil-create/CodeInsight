#include<bits/stdc++.h>
using namespace std;
const int N=510;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,m,h,w,c[N][N],a[N][N];
void modify(int x,int y,int v) {
    for(int i=x;i<=n;i+=i&-i)
        for(int j=y;j<=m;j+=j&-j) c[i][j]+=v;
}
int query(int x,int y) {
    int ret=0;
    for(int i=x;i;i-=i&-i)
        for(int j=y;j;j-=j&-j) ret+=c[i][j];
    return ret;
}
int main() {
    n=gi(),m=gi(),h=gi(),w=gi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) modify(i,j,1000),a[i][j]=1000;
    for(int i=h;i<=n;i++)
        for(int j=w;j<=m;j++) {
            int t=query(i,j)-query(i-h,j)-query(i,j-w)+query(i-h,j-w);
            if(t>=0) a[i][j]-=t+1,modify(i,j,-t-1);
            if(a[i][j]<-1e9) return puts("No"),0;
        }
    if(query(n,m)>0) {
        puts("Yes");
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
    }
    else puts("No");
    return 0;
}
