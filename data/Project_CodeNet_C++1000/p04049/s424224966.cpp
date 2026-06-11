#include<bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int inf = 1<<30;
vector<int> e[2020];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    auto bfs = [=](auto && e,int i){
        vector<int> dict(n,inf);
        dict[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto to : e[cur]){
                if(dict[to] != inf) continue;
                dict[to] = dict[cur] + 1;
                q.push(to);
            }
        }
        return dict;
    };
    vector<vector<int>> target(n);
    vector<int> sz(n);
    for(int i=0;i<n;++i){
        auto d = bfs(e,i);
        for(int j=0;j<n;++j){
            if(d[j] > k){
                target[i].push_back(j);
                sz[i]++;
            }
        }
    }
    int ret = 0;
    while(true){
        auto it = max_element(sz.begin(),sz.end());
        if(*it == 0) break;
        int n = it - sz.begin();
        sz[n] = 0;
        for(auto to : target[n]){
            sz[to]--;
        }
        ret++;
    }
    cout << ret << endl;
    return 0;
}
