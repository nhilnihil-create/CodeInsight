#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
const ll INF = 1001001001001;
bool visit[303][303];
int main(){
    int n; cin >> n;
    ll cost[n][n];
    ll d[n][n];
    rep(i,n)rep(j,n) d[i][j] = INF;
    rep(i,n){
        rep(j,n){
            cin >> cost[i][j];
            d[i][j] = cost[i][j];
        }
    }
    ll res = 0;
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(d[i][j] == d[i][k]+d[k][j] && i<j && k!=i && k!=j && visit[i][j]==0 ){
                    res += d[i][j];
                    visit[i][j]=1;
                }
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    bool ok = 1;
    ll ans = 0;
    rep(i,n){
        rep(j,n){
            if(i<j) ans += d[i][j];
            if(d[i][j] != cost[i][j]){
                ok = 0;
                break;
            }
        }
    }
    if(!ok) cout << -1 << endl;
    else cout << ans-res << endl;
}
