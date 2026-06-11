#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,L,T;
    cin >> N >> L >> T;
    vec<ll> X(N),W(N);
    map<ll,ll> mp;
    vvec<ll> list(2);
    L *= 2;
    T *= 2;
    for(ll i=0;i<N;i++){
        cin >> X[i] >> W[i];
        W[i]--;
        X[i] *= 2;
        mp[X[i]] = i;
        list[W[i]].emplace_back(X[i]);
    }
    if(list[1].empty()){
        for(ll i=0;i<N;i++) cout << (X[i]+T)%L/2 << "\n";
        return 0;
    }
    if(list[0].empty()){
        for(ll i=0;i<N;i++) cout << (X[i]-T+L)%L/2 << "\n";
        return 0;
    }
    for(ll k=0;k<2;k++) sort(list[k].begin(),list[k].end());
    
    auto dist = [&](ll clock,ll counter){
        if(clock<counter) return counter-clock;
        else return L-(clock-counter);
    };

    auto next_time = [&](ll clock,ll counter,ll ti){
        ll p0 = (clock+ti)%L,p1 = (counter-ti+L)%L;
        ll d = dist(p0,p1);
        return ti+d/2;
    };

    vec<ll> id(2);
    ll ti = 0,now = 0;
    bool exist = mp[list[1][0]]==0;
    vec<ll> si = {(ll) list[0].size(),(ll) list[1].size()};
    if(exist){
        id[0] = si[0]-1;
    }
    while(true){
        ll net = next_time(list[0][id[0]],list[1][id[1]],ti);
//        cerr << ti << " " << net << "\n";
        if(net<L){
            exist ^= true;
            now = mp[list[exist][id[exist]]];
            if(exist) (id[0] += -1+si[0])%=si[0];
            else (id[1] += 1)%=si[1];;
        }else break;
        ti = net;
    }
    ll n = T/L;
    now = ((ll) now*n)%N;
    if(!W[now]){
        for(ll i=0;i<si[0];i++) if(mp[list[0][i]]==now){
            id[0] = i;
            break;
        }
        id[1] = 0;
        for(ll j=0;j<si[1];j++) if(X[now]<list[1][j]){
            id[1] = j;
            break;
        }
        exist = false;
    }else{
        for(ll i=0;i<si[1];i++) if(mp[list[1][i]]==now){
            id[1] = i;
            break;
        }
        id[0] = si[0]-1;
        for(ll j=0;j<si[0];j++){
            if(list[0][j]<X[now]){
                id[0] = j;
            }else break;
        }
        exist = true;
    }
    ti = 0;
    while(true){
        ll net = next_time(list[0][id[0]],list[1][id[1]],ti);
        if(net<(T%L)){
            exist ^= true;
            now = mp[list[exist][id[exist]]];
            if(exist) (id[0] += -1+si[0])%=si[0];
            else (id[1] += 1)%=si[1];;
        }else break;
        ti = net;
    }
    vec<ll> ans(N);
    vec<ll> v;
    ll start = -1;
    for(ll i=0;i<N;i++){
        ll l = (X[i]+(W[i]? -1:1)*T+(ll) T*L)%L;
        v.push_back(l);
        if(i==now) start = l;
    }
    sort(v.begin(),v.end());
    ll sid = 0;
    for(ll i=0;i<N;i++) if(v[i]==start){
        sid = i;
        if(!W[now]) break;
    }
    for(ll i=0;i<N;i++) cout << v[(sid+i)%N]/2 << "\n";
}