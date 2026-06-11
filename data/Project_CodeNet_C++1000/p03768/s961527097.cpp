#include <bits/stdc++.h>
using namespace std;



int main(){
    int N, M, Q;
    cin >> N >> M;
    vector<int> edges[100000];
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    cin >> Q;
    vector<int> V(Q), D(Q), C(Q);
    for(int i=0; i<Q; i++){
        cin >> V[i] >> D[i] >> C[i];
        V[i]--;
    }

    vector<int> ans(N);
    bitset<11> done[100000];

    for(int i=Q-1; i>=0; i--){
        queue<pair<int, int>> que;
        que.push({V[i], D[i]});
        while(que.size()){
            auto p = que.front(); que.pop();
            int s = p.first, d = p.second;
            if(d < 0) continue;
            if(ans[s] == 0) ans[s] = C[i];
            if(done[s][d]) continue;
            done[s][d] = 1;
            for(int t : edges[s]) que.push({t, d-1});
        }
    }
    for(int a : ans) cout << a << endl;
}