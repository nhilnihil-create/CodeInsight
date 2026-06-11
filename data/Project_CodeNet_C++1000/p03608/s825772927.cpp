#include<bits/stdc++.h>
using ll = long long;

int main()
{
    ll n,m,r;
    std::cin >> n >> m >> r;
    std::vector<ll> city(r);
    for(ll i = 0; i < r; i++){std::cin >> city[i]; city[i]--;}
    std::vector<std::vector<ll>> dist(n,std::vector<ll>(n,100000000000000000));
    for(ll i = 0; i < m; i++){
        ll a,b,c;
        std::cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    //std::cout << 334334 << std::endl;
    for(int i = 0; i < n; i++)dist[i][i] = 0;
    for(ll k = 0; k < n; k++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll min = 10000000000000000;
    std::sort(city.begin(), city.end());
    do{
        ll cur = 0;
        for(int i = 1; i < r; i++){
            cur += dist[city[i]][city[i - 1]];
        }
        min = std::min(cur,min);
    }while(std::next_permutation(city.begin(), city.end()));

    std::cout << min << std::endl;





}
