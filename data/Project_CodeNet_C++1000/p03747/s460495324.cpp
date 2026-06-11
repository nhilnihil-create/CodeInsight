#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,l,t,k,cnt,w[N];
int main()
{
    scanf("%d%d%d",&n,&l,&t);
    for(int i=1;i<=n;i++) {scanf("%d%d",&w[i],&k),w[i]+=(k==1)?t:-t,cnt+=w[i]/l; if(w[i]%l<0) cnt--; ((w[i]%=l)+=l)%=l;}
    sort(w+1,w+n+1),((cnt%=n)+=n)%=n; for(int i=cnt+1;i<=n;i++) printf("%d\n",w[i]);
    for(int i=1;i<=cnt;i++) printf("%d\n",w[i]);
    return 0;
}