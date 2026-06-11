#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    ll N,M; cin >> N >> M;
    vector<ll> red(N); red[0]=1;
    vector<ll> total(N);
    for(ll i=0;i<N;i++)total[i]=1;

    for(ll i=0;i<M;i++){
        ll x,y; cin >> x >> y; x--;y--;
        if(red[x]){
            if(total[x]==0) {red[x]=0;}
            if(total[x]==1) {red[x]=0; red[y]=1;}
            else red[y]=1;
        }
        total[x]--; total[y]++;
    }
    ll ans=0;
    for(ll i=0;i<N;i++){
        if(red[i]&&total[i])ans++;
    }
    cout << ans << endl;
}

