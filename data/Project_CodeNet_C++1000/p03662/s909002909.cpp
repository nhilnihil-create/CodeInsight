#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll N;
vector<ll> v[(ll)1e5];
void bfs(ll start, ll *dist){
    memset(dist, 1145148931919810, N);
    queue<ll> q;
    q.push(start);
    bool used[N] = {};
    used[start] = 1;
    dist[start] = 0;
    while(q.size()){
        ll now = q.front();
        q.pop();
        for(ll next : v[now]){
            if(used[next]) continue;
            dist[next] = dist[now] + 1;
            used[next] = 1;
            q.push(next);
        }
    }
}
int main(){
    cin >> N;
    for(ll i = 1; i < N; i++){
        ll a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }
    ll po[N], yo[N];
    bfs(0, po);
    bfs(N - 1, yo);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(po[i] <= yo[i]) ans++;
        else ans--;
    }
    cout << (ans <= 0 ? "Snuke\n" : "Fennec\n");
    return 0;
}