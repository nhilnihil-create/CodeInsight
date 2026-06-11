#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
ll N,A,B;
ll H[101010];

ll i, j, k;


bool bs(ll aa){
    ll i, ct = 0;
    fornum(i,0,N){
        ll h = H[i];
        h -= aa * B;
        if(h>0){
            ct += (h - 1) / (A - B) + 1;
        }
    }
    return aa >= ct;
}

int main(){
    scanf("%lld%lld%lld", &N, &A, &B);
    fornum(i,0,N){
        scanf("%lld", &H[i]);
    }
    ll l = 0, r = 1e9;
    while(l<r){
        ll c = (l + r) / 2;
        if(bs(c)){
            r = c;
        }else{
            l = c + 1;
        }
    }
    printf("%lld", l);
    return 0;
}