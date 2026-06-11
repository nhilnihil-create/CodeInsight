#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <numeric>
#include <iomanip>
#define ll long long
#define pi 3.14159265358979323846
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
/*
 vector<vector<ll>> g(n+1);
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dist(n+1, -1);
    queue<ll> que;
    que.push(1);
    dist[1] = 0;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
*/

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    for(ll i = 0; i < c-a; i++)
        s+='R';
    for(ll i = 0; i < d-b; i++)
        s+='U';
    for(ll i = 0; i < c-a; i++)
        s+='L';
    for(ll i = 0; i < d-b+1; i++)
        s+='D';
    for(ll i = 0; i < c-a+1; i++)
        s+='R';
    for(ll i = 0; i < d-b+1; i++)
        s+='U';
    s+="LU";
    for(ll i = 0; i < c-a+1; i++)
        s+='L';
    for(ll i = 0; i < d-b+1; i++)
        s+='D';
    s+='R';
    cout << s << endl;
    return 0;
}
