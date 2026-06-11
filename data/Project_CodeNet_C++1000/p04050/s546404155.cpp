#include <bits/stdc++.h>
#define N 1000500
using namespace std;

int a[N],b[N],n,m,cnt,t;

inline int rd() {
    int x=0,f=1;char ch=getchar();
    while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
    n = rd(), m = rd();
    for (int _=1;_<=m;_++) a[_] = rd();
    sort(a+1,a+m+1, greater<int>() );

    if (m==1) {

        if (n==1) {printf("1\n1\n1\n"); return 0;}

        printf("%d\n",a[1]);
        printf("2\n");
        printf("%d %d\n",a[1]-1,1);
        return 0;
    }

    for (int _=1;_<=m;_++) (a[_]&1) ? ++cnt : 0;
    if (cnt > 2) return puts("Impossible"), 0;
    for (int _=2;_<=m-1;_++)
        if (a[_]&1) (a[1]&1) ? swap(a[_],a[m]) : swap(a[_],a[1]);
    for (int _=1;_<=m;_++) printf("%d%c",a[_],_==m?'\n':' ');
    (a[1]==1) ? (t=2) : (t=1);
    printf("%d\n",m-t+1);
    memcpy(b,a,sizeof(a));
    b[1]--, b[m]++;
    for (int _=t;_<=m;_++) printf("%d%c",b[_],_==m?'\n':' ');
    return 0;
}