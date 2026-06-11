#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
int n,k,a[max_n];
ll s[max_n];
int bit[max_n],tot;
void update(int i,int x){
    for(;i<=tot;i+=i&-i)bit[i]+=x;
}
int query(int i){
    int res=0;
    for(;i;i-=i&-i)res+=bit[i];
    return res;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=0;i<=n;i++)s[i]-=1ll*k*i;
    vector<ll> lsh;
    for(int i=0;i<=n;i++)lsh.push_back(s[i]);
    sort(lsh.begin(),lsh.end());lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for(int i=0;i<=n;i++)s[i]=lower_bound(lsh.begin(),lsh.end(),s[i])-lsh.begin()+1;
    tot=lsh.size();
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=query(s[i]);
        update(s[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}