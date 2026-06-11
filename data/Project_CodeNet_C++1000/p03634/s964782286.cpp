#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int N;
    cin >> N;
    vector<vector<P>>ki(N);
    for(int i = 0; i < N-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        ki[a].push_back({b,c});
        ki[b].push_back({a,c});
    }
    int Q,K;
    cin >> Q >> K;
    vector<int>cnt(N,-1);
    cnt[K-1] = 0;
    //cntは、頂点iから、Kまでの距離を指す
    queue<int> que;
    que.push(K-1);
    while(!que.empty()) {
        int X = que.front();
        que.pop();
        for(int i = 0; i < ki[X].size(); i++) {
            if(cnt[ki[X][i].first] == -1) {
                que.push(ki[X][i].first);
                cnt[ki[X][i].first] = cnt[X]+ki[X][i].second;
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