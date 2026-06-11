#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)

ll N,x[101010];
ll i, j, k,ans;
int main(){
    scanf("%lld", &N);
    fornum(i,0,N){
        scanf("%lld", &x[i]);
    }
    //printf("%lld\n", MOD);
    k = 0;
    ans = 1;
    fornum(i,0,N){
        //printf("%lld:%lld\n",(i-k*2)*2, x[i]);
        if((i-k)*2<x[i])
            continue;
        ans = ans * (i+1-k) % MOD;
        k++;
        
    }
    //printf("%lld:%lld\n",k, i);
    fornum(k,k,N){
        ans = ans * (N - k) % MOD;
    }
    printf("%lld",ans);

    return 0;
}