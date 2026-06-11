#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=500000;
int n,w[N],tmp[N];
int main()
{
    scanf("%d",&n);int cnt=0;
    for(int i=1;i<=n;i++)scanf("%d",w+i),tmp[i]=w[i];
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;i++)w[i]=lower_bound(tmp+1,tmp+n+1,w[i])-tmp,cnt+=(i&1)^(w[i]&1);
    cout<<(cnt>>1)<<endl;
}