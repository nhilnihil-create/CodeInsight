#include <bits/stdc++.h>
using namespace std;

int a[1000005],n,t;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&t), a[t]++;
    int cnt = 0;
    for(int i=1;i<=100000;i++) if(a[i]>1) cnt+=a[i]-1;
    if(cnt&1) n-=cnt+1;
    else n-=cnt;
    cout<<n<<endl;
}
