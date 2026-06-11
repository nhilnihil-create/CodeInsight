#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[100010],xx[100010],w[100010],l,r,t,n,m,c;
int main(){
    scanf("%lld%lld%lld",&n,&l,&t);
    for(int i=1;i<=n;i++)
    	scanf("%lld%lld",&x[i],&w[i]);
    for(int i=1;i<=n;i++){
        if(w[i]==2)
			w[i]=-1;
        r=x[i]+w[i]*t;
        if(r>0)
			(c+=r/l)%=n;
        else if(r<0)
			(c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    sort(xx+1,xx+n+1);
    c=(c+n)%n;
    for(int i=c+1;i<=n;i++)
    	printf("%lld\n",xx[i]);
    for(int i=1;i<=c;i++)
    	printf("%lld\n",xx[i]);
    return 0;
}