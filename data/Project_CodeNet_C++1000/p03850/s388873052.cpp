#include<bits/stdc++.h>
#define me(a,x) memset(a,x,sizeof a)
#define cp(a,x) memcpy(a,x,sizeof a)
using namespace std;
typedef long long LL;
const int N=1e5+3;
int a[N]; char s[N];
LL p[N],f[N];
int main(){
    int n,i,j; scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(i<n)scanf("\n%c",&s[i+1]);
    }
    for(i=n;i;--i) p[i]=p[i+1]+a[i];
    j=n+1;
    for(i=n;i>1;--i){
        if(s[i]=='+')continue;
        f[i]=max( f[j]+p[i+1]-p[j],p[j]-(p[i+1]-p[j]) )-a[i];
        j=i;
    }
    printf("%lld\n",f[j]+p[1]-p[j]);
    return 0;
}