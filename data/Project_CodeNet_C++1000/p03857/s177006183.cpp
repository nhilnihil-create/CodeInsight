#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, l;
    cin >> n >> k >> l;
    vector<vector<int> >g1(n + 3), g2(n + 3);
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    for(int i = 0; i < l; i++){
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    vector<int>a(n + 3), b(n + 3), vis(n + 3, 0);
    queue<int>q;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cnt++;
            q.push(i);
            a[i] = cnt;
            vis[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int j = 0; j < g1[u].size(); j++){
                    int v = g1[u][j];
                    if(vis[v] == 0){
                        vis[v] = 1;
                        a[v] = cnt;
                        q.push(v);
                    }
                }
            }
        }
    }
    cnt = 0;
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cnt++;
            q.push(i);
            b[i] = cnt;
            vis[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int j = 0; j < g2[u].size(); j++){
                    int v = g2[u][j];
                    if(vis[v] == 0){
                        vis[v] = 1;
                        b[v] = cnt;
                        q.push(v);
                    }
                }
            }
        }
    }
    map<pair<int, int>, int>mp;
    for(int i = 1; i <= n; i++){
        mp[make_pair(a[i], b[i])]++;
    }
    for(int i = 1; i <= n; i++){
        cout << mp[make_pair(a[i], b[i])] << ' ';
    }
    return 0;
}