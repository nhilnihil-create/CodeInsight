#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
int n;
ll h[max_n];
int a,b;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    a-=b;
    for(int i=1;i<=n;i++)scanf("%lld",h+i);
    int l=0,r=1000000000/b+1;
    int mid,ans;
    function<bool(int)> check=[&](int x){
        ll res=0;
        for(int i=1;i<=n;i++){
            ll tmp=h[i]-1ll*b*x;
            if(tmp>=0)res+=(tmp+a-1)/a;
        }
        return res<=x;
    };
    while(l<=r){
        mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}