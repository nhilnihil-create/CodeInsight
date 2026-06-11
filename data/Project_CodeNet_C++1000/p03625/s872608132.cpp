#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long n;
long long a[N];
long long cnt[3],tot=0;
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=n;i>=1;i--)if(a[i]==a[i-1]){cnt[++tot]=a[i];i--;if(tot==2)break;}
    printf("%lld\n",cnt[1]*cnt[2]);
    return 0;
}