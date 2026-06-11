#include <bits/stdc++.h>

int n,x;
int cnt[100005];

typedef long long ll;
const ll MOD = 1e9 + 7;

ll Pow(ll a,int b){
    ll Now = 1;
    while(b > 0){
        if(b & 1) Now = a * Now % MOD;
        a = a * a  % MOD;
        b >>= 1;
    }
    return Now;
}

int main(){
    scanf("%d", &n);
    if(n % 2 == 0){
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            cnt[x]++;
        }
        bool flag = true;
        for(int i = 1; i < n; i += 2){
            if(cnt[i] != 2){
                flag = false;
                break;
            }
        }
        if(flag) printf("%lld\n",Pow(2,n/2));
        else puts("0");
    }
    else{
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            cnt[x]++;
        }
        bool flag = true;
        if(cnt[0] != 1) flag = false;
        for(int i = 2; i < n; i += 2){
            if(cnt[i] != 2){
                flag = false;
                break;
            }
        }
        if(flag) printf("%lld\n",Pow(2,n/2));
        else puts("0");
    }
    return 0;
}

