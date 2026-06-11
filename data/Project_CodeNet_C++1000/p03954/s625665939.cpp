#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
    char ch=nc(); int i=0,f=1;
    while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
    while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
    return i*f;
}

const int N=2e5+50;
int n,a[N];
#define up(i,j) ((a[i]>=v) && (a[j]>=v))
#define dn(i,j) ((a[i]<v) && (a[j]<v))
inline bool check(int v) {
    for(int i=0;i<n-1;i++) {
        if(up(n+i,n+i+1) || up(n-i,n-i-1)) return 1;
        if(dn(n+i,n+i+1) || dn(n-i,n-i-1)) return 0;
    } return up(1,1);
}
int main() {
    n=rd(); for(int i=1;i<n*2;++i) a[i]=rd();
    int l=1, r=*max_element(a+1,a+2*n), ans=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    } cout<<ans<<'\n';
}