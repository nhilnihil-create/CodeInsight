#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll two[75],s;
int a[210],b[75],c[210];
int i,j,k,l,t,n,m,mx,tot,top,now;
int main(){
    cin>>s;
    two[0]=1;
    for(i=1;i<=50;i++) two[i]=(ll)two[i-1]*2;
    mx=50;
    while (two[mx]>s) mx--;
    s-=two[mx];
    m=mx;
    tot=2*m;
    now=m;
    c[++top]=now+1;
    c[++top]=now+1;
    now++;
    tot+=2;
    while (s){
        while (two[mx]>s) mx--;
        s-=two[mx];
        b[mx]=++now;
        c[++top]=now;
        tot+=2;
    }
    printf("%d\n",tot);
    for(i=0;i<=m;i++){
        if (i) printf("%d ",i);
        if (b[i]) printf("%d ",b[i]);
    }
    for(i=1;i<=m;i++) printf("%d ",i);
    for(i=1;i<=top;i++) printf("%d ",c[i]);
}
