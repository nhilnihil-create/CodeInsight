#include <bits/stdc++.h>
using namespace std;
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scs(s) scanf("%s",s)
#ifndef GET_MACRO

#define GET_MACRO(__1,__2,__3,NAME,...) NAME

#endif // GET_MACRO

#define sci(...) GET_MACRO(__VA_ARGS__,sci3,sci2,sci1)(__VA_ARGS__)
#define ll long long

int main(){
    //freopen("input.txt","r",stdin);
    ll n,m,i,j,*data1,*data2,*tdata,ans,t1,t2,t3,md=1000000007ll;
    data1=new ll[100000];
    data2=new ll[100000];
    tdata=new ll[100000];
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&tdata[i]);
    }
    sort(tdata,tdata+n);
    for(i=1;i<n;i++){
        data1[i-1]=tdata[i]-tdata[i-1];
    }
    for(i=0;i<m;i++){
        scanf("%lld",&tdata[i]);
    }
    sort(tdata,tdata+m);
    for(i=1;i<m;i++){
        data2[i-1]=tdata[i]-tdata[i-1];
    }
    ans=0ll;
    n--;
    for(i=0;i<n;i++){
        t1=((i+1)*(n-i))%md;
        ans+=((t1*data1[i])%md);
        ans%=md;
    }
    m--;
    t2=0;
    for(i=0;i<m;i++){
        t1=((i+1)*(m-i))%md;
        t2+=((t1*data2[i])%md);
        t2%=md;
    }
    ans=(ans*t2)%md;
    printf("%lld\n",ans);

    return 0;
}
