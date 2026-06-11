#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,r;
ll memo[8];
ll dist[222][222];

int main(){
    cin >> n >> m >> r;
    for(ll i=0;i<r;i++) cin >> memo[i];
    sort(memo,memo+r);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i!=j) dist[i][j]=1e9;
        }
    }
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        dist[a][b]=c;
        dist[b][a]=c;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    ll res=1e9;
    do{
        ll count=0;
        for(ll i=0;i<r-1;i++){
            count+=dist[memo[i]][memo[i+1]];
        }
        res=min(res,count);
    } while(next_permutation(memo,memo+r));
    cout << res << endl;
}  
