#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e5+5;
int a[maxn],n;
bool b[maxn];
bool check(){
    int i,m=n-1;
    for (i=0;i<n-1;i++){
        if (b[m-i]==b[m-i-1]) return b[m-i];
        if (b[m+i]==b[m+i+1]) return b[m+i];
    }
    return b[0];
}
int sear(int l,int r){
    if (l+1==r) return l;
    int m=(l+r)/2;
    int i;
    for (i=0;i<2*n-1;i++) b[i]=(a[i]<=m);
    if (check()) return sear(l,m);
    else return sear(m,r);
}
int main(){
    int i;
    scanf("%d",&n);
    for (i=0;i<2*n-1;i++) scanf("%d",&a[i]);
    printf("%d",sear(1,2*n)+1);
    return 0;
}
