//by Sshwy
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)

namespace RA{
    int rnd(int p){return 1ll*rand()*rand()%p;}
    int rnd(int L,int R){return rnd(R-L+1)+L;}
}
const int N=1e5+5;
int n;
int a[N],o[N];
long long sa[N],ps;

int main(){
    scanf("%d",&n);
    scanf("%d",&a[1]);
    FOR(i,2,n){
        char op[5];
        scanf("%s%d",op,&a[i]);
        if(op[0]=='-')o[i]=-1;
        else o[i]=1;
    }
    ROF(i,n,1)sa[i]=sa[i+1]+a[i];
    o[1]=1;
    long long ans=-1e18;
    FOR(i,1,n){
        ps+=a[i]*o[i];
        if(i<n && o[i+1]==-1){
            long long s=a[i+1];
            int pos=i+2;
            while(pos<=n && o[pos]==1)s+=a[pos],++pos;
            ans=max(ans,sa[pos]-s+ps);
        }
    }
    ans=max(ans,ps);
    printf("%lld\n",ans);
    return 0;
}
