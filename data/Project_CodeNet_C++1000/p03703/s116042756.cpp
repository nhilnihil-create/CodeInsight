#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const int MAX=200000+10; 
int n,k;
ll a[MAX];
ll b[MAX];
ll s[MAX];
map<ll, int>mp;
int lowbit(int x)
{
    return (x&-x);
}
 
void modify(int x,int num)
{
    while(x<=n+1){
        a[x]+=(long long)num;
        x+=lowbit(x);
    }
}
 
long long sum(int x)
{
    long long ans=0;
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}
 
int main()
{
    scanf("%d %d",&n,&k);
    s[0]=0;b[0]=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+(long long)(x-k);
        b[i]=s[i];
    }
    sort(b,b+1+n);
    int tot=0;
    for(int i=0;i<=n;i++)
        if(!mp.count(b[i]))mp[b[i]]=++tot; 
    long long cnt=0;
    memset(a,0,sizeof(a));
    for(int i=0;i<=n;i++){
        cnt+=sum(mp[s[i]]);
        modify(mp[s[i]],1);
    }
    printf("%lld\n",cnt);
    return 0;
} 