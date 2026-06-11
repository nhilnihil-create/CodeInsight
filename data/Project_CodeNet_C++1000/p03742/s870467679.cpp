#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAX=30;
const ll INF=0x3f3f3f3f3f3f3f;
ll p,q,mux[MAX][MAX],tmp[MAX];
ll find_mux(ll a,ll b){
    int tmp[MAX];
    if(mux[a][b]==-1){
        mux[a][b]=0;
        for(ll i=0;i<MAX;i++) tmp[i]=0;
        for(ll i=2;i<=a;i+=2) tmp[find_mux(a-i,b+i/2)]=1;
        for(ll i=2;i<=b;i+=2) tmp[find_mux(a+i/2,b-i)]=1;
        for(ll i=0;i<MAX;i++){
            if(!tmp[i]) break;
            mux[a][b]++;
        }
    }
    return mux[a][b];
}
int main(){
    scanf("%lld%lld",&p,&q);
    if(abs(p-q)<=1) printf("Brown\n");
    else printf("Alice\n");
}
