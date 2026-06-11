#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;

using value_type = i64;


signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        edges[--a].emplace_back(--b);
        edges[b].emplace_back(a);
    }
    unordered_set<int> s;
    deque<int> que;
    int a = 0, b = edges[0][0];
    s.insert(a);
    s.insert(b);
    que.push_front(a);
    que.push_back(b);
    while(1){
        bool fl = false;
        for(auto x : edges[a]){
            if(s.find(x) == s.end()){
                que.push_front(a = x);
                s.insert(a);
                fl = 1;
                break;
            }
        }
        for(auto x : edges[b]){
            if(s.find(x) == s.end()){
                que.push_back(b = x);
                s.insert(b);
                fl = 1;
                break;
            }
        }
        if(!fl)
            break;
    }
    cout << que.size() << endl;
    while(!que.empty()){
        cout << que.front() + 1 << " \n"[que.size() == 1];
        que.pop_front();
    }

}
