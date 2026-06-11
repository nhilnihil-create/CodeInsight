#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5,inf=1e9+10;
int a[maxn];
int main(){
    int i,n,p,q;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    q=a[n-1];
    for (i=n-1;i;i--) a[i]=a[i]-a[i-1]+1;
    a[0]=inf;
    for (i=1;i<n-1;i++) if (a[i]==1&&(a[i+1]&1)){
        a[i]++; a[i+1]--;
    }
    p=n-1;
    while (q>a[p]) q-=a[p--];
    if ((a[p]&1)&&q==a[p]) puts("First");
    else puts((q&1)?"Second":"First");
    return 0;
}