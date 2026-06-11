#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll h[100005];

ll myceil(ll a, ll b){
    if(a<0)
        return 0;
    return (a/b)+((a%b)>0);
}

int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    a-=b;
    for(int i = 0; i<n; i++)
        scanf("%lld",&h[i]);
    int s = 1,e=1000000000,ans=-1;
    while(s<=e){
        ll m = (s+e)/2;
        ll amt = 0;
        for(int i = 0; i<n; i++)
            amt+=myceil(h[i]-(m*b),a);
        if(amt<=m){
            ans = m;
            e = m-1;
        }else
            s = m+1;
    }
    printf("%d\n",ans);
    return 0;
}