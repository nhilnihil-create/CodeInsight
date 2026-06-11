#include<bits/stdc++.h>
long long x[1000001],xx[1000001],w[1000001],i,j,k,l,r,s,t,n,m,c;
int main(){
    scanf("%lld%lld%lld",&n,&l,&t);    
    for(register int i=1;i<=n;++i)
        scanf("%lld%lld",&x[i],&w[i]);
    for(register int i=1;i<=n;++i)
    {
        if (w[i]==2) w[i]=-1;
        r=x[i]+w[i]*t;
        if (r>0) (c+=r/l)%=n;
        else if (r<0) (c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    std::sort(xx+1,xx+n+1);
    c=(c+n)%n;
    for(register int i=c+1;i<=n;++i)printf("%d\n",xx[i]);
    for(register int i=1;i<=c;++i)printf("%d\n",xx[i]);
}