#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a=1000,b,n,p,x,ans=1000;
    scanf("%lld",&n);
    for (long long i=1;i<100001;i++) {
        if (n%i==0) {
            a=1;
            b=1;
            p=max(i,n/i);
            for (long long j=1;j<12;j++)  {
                if (p/b>0) a=j;
                b*=10;
            }
            ans=min(ans,a);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
