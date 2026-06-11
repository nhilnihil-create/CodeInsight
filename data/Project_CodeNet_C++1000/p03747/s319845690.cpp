#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int x[maxn],xx[maxn],w[maxn];
int i,j,k,l,r,s,t,n,m;
long long c;
int main()
{
    cin>>n>>l>>t;
    for(i=1;i<=n;i++) cin>>x[i]>>w[i];
    for(i=1;i<=n;i++) {
        if(w[i]==2) w[i]=-1;
        r=x[i]+w[i]*t;
        if(r>0) (c+=r/l)%=n;
        else if(r<0) (c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    sort(xx+1,xx+n+1);
    c=(c+n)%n;
    for(i=c+1;i<=n;i++) printf("%d\n",xx[i]);
    for(i=1;i<=c;i++) printf("%d\n",xx[i]);
}