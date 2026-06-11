#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e16+7;
typedef pair<int,int> P;
signed main(){
    int N;
    cin >> N;
    vector<vector<P>>road(N);
    for(int i = 0; i < N-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        road[a].push_back({b,c});
        road[b].push_back({a,c});
    }
    int Q,K;
    cin >> Q >> K;
    K--;
    priority_queue<P,vector<P>,greater<P>> que;
    vector<int>cnt(N,INF);
    cnt[K] = 0;
    que.push({0,K});
    while(!que.empty()) {
        P x = que.top();
        que.pop();
        if(cnt[x.second] < x.first) {
            continue;
        }
        for(int i = 0; i < road[x.second].size(); i++) {
            if(cnt[road[x.second][i].first] > x.first+road[x.second][i].second) {
                cnt[road[x.second][i].first] =  x.first+road[x.second][i].second;
                que.push({cnt[road[x.second][i].first],road[x.second][i].first});
            }
        }
    }
    for(int i = 0; i < Q; i++) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        cout << cnt[x]+cnt[y] << endl;
    }
}


