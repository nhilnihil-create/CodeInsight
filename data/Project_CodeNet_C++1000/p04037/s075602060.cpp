#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,a[N],ans;
inline int rd() {   int r;scanf("%d",&r);return r;}
bool cmp(int p1,int p2) {return p1 > p2;}
int main(){
    n = rd();
    for (int i=1;i<=n;i++) a[i] = rd();
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) if(i+1>a[i+1]) {
        for(int j=i+1;a[j]==i;j++) ans^=1;
        ans |= (a[i] - i) & 1;
        if (ans) puts("First"); else puts("Second");
        return 0;
    }
    return 0;
}